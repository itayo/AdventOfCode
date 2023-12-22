#include <iostream>
#include <queue>
#include "day.h"


void Day::PrepareData() {
}

struct RetrieveKey {
    template<typename T>
    typename T::first_type operator()(T keyValuePair) const {
        return keyValuePair.first;
    }
};

bool cointains(const std::vector<AoC::Vector2D> &vec, AoC::Vector2D t) {
    for (auto v: vec) {
        if (t.X() == v.X()) {
            if (v.Y() == t.Y()) return true;
        }
    }
    return false;
}

struct tObject {
    tObject() : pos(0, 0) {}

    tObject(AoC::Vector2D p, uint64_t s) : pos(p), steps(s) {}

    AoC::Vector2D pos;
    uint64_t steps;
};


uint64_t Day::Walk(uint64_t distance) {
    AoC::Vector2D gridSize(m_mapA.Columns(), m_mapA.Rows());
    std::deque<std::tuple<AoC::Vector2D, uint64_t>> queue;
    std::map<std::tuple<uint64_t, uint64_t>, tObject> visited;
    AoC::Vector2D start = m_mapA.FindPos('S');
    queue.push_back(std::tuple(start, 0));
    std::vector<AoC::Vector2D> dirs{{1,  0},
                                    {-1, 0},
                                    {0,  1},
                                    {0,  -1}};
    while (!queue.empty()) {
        auto [pos, currSteps] = queue.front();
        currSteps += 1;
        queue.pop_front();
        if (distance < currSteps) continue;


        for (auto dir: dirs) {
            AoC::Vector2D n = pos + dir;
            std::tuple<uint64_t, uint64_t> tup = std::tuple(n.X(), n.Y());
            if (visited.find(tup) == visited.end() && m_mapA.Exists(n % gridSize) && m_mapA.Get(n % gridSize) != '#') {
                auto object = tObject(n, currSteps);
                visited[tup] = object;
                queue.emplace_back(std::tuple(n, currSteps));
            }
        }

    }
    uint64_t res = 0;
    for (auto visit: visited) {
        if (visit.second.steps % 2 == distance % 2)
            res += 1;

    }
    return res;

}

void Day::RunA(bool secondData) {
    m_resultA = Walk(64);

}

void Day::RunB() {
}


void Day::Report() {
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}