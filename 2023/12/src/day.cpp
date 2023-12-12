#include <iostream>
#include <numeric>
#include <thread>
#include <future>
#include "day.h"

void Day::PrepareData() {

}

bool GroupsCheck(std::string &lut, size_t &pos, std::vector<uint64_t> &broken) {
    std::vector<uint64_t> testGroups;
    uint64_t count = 0;
    for (size_t checkPos = 0; checkPos < pos; ++checkPos) {
        switch (lut[checkPos]) {
            case '#':
                ++count;
                break;
            case '.':
                if (count > 0) testGroups.emplace_back(count);
                count = 0;
                break;
        }

    }
    for (int checkGroup = 0; checkGroup < testGroups.size(); ++checkGroup) {
        if (broken[checkGroup] != testGroups[checkGroup]) {
            return false;
        }
    }
    return true;
}
std::mutex print;

int RegexCalc(std::string &rx, std::string &lut) {
    std::regex regex(rx);
    std::smatch matcher;
    return regex_match(lut, matcher, regex) ? 1 : 0;
}



int MatchData(std::string lut, size_t pos, std::string &rx, std::vector<uint64_t> &broken) {
    int counter = 0;
    if (!GroupsCheck(lut, pos, broken)) {
        return 0;
    }
    if (pos >= lut.size()) {
        return RegexCalc(rx, lut);
    }
    while (lut[pos] != '?' && pos < lut.size()) ++pos;

    lut[pos] = '#';
    counter += MatchData(lut, pos, rx, broken);
    lut[pos] = '.';
    counter += MatchData(lut, pos, rx, broken);
    return counter;
}

void MatchDataWithPromise(std::promise<uint64_t> &&result, tRow row, int thread) {
    {
        std::lock_guard<std::mutex> lockGuard(print);
        std::cout<< "thread " << thread << " started" << std::endl;
    }
    uint64_t thisRun = MatchData(row.line, 0, row.rx, row.broken) / 2;
    result.set_value(thisRun);
    {
        std::lock_guard<std::mutex> lockGuard(print);
        std::cout<< "thread " << thread << " finished" << std::endl;
    }
}
void Day::RunA(bool secondData) {

    m_resultA = 0;
    for (auto row: m_rowsA) {
        uint64_t thisRun = MatchData(row.line, 0, row.rx, row.broken);
        m_resultA += thisRun;
    }
    m_resultA /= 2;
}

std::string Day::GenerateRegex(std::vector<uint64_t> &groups) {
    std::string rx = "\\.*";
    for (uint64_t group: groups) {
        for (int i = 0; i < group; ++i) { rx.append("#"); }
        rx.append("\\.+");
    }
    return rx;
}

void Day::RunB() {
    m_resultB = 0;
    size_t threadCount = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    std::vector<std::promise<uint64_t>> promises(m_rowsB.size());
    std::vector<std::future<uint64_t>> results(m_rowsB.size());

    std::cout << "total runs = " << m_rowsB.size() << std::endl;
    for (int i = 0; i < m_rowsB.size(); ++i) {
        tRow &row = m_rowsB[i];
        results[i] = promises[i].get_future();
        threads.emplace_back(&MatchDataWithPromise, std::move(promises[i]), row, i);
    }
    std::for_each(threads.begin(), threads.end(), [](std::thread &t) { t.join(); });
    for (auto& result: results) {
        m_resultB += result.get();
    }
}

void Day::Report() {
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}