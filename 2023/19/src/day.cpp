#include <iostream>
#include <numeric>
#include <queue>
#include "day.h"

void Day::PrepareData() {}


void Day::RunA(bool secondData) {
    for (auto xmas: m_xmasA) {
        std::string location = "in";
        while (location != "R" && location != "A") {
            std::string newLocation = "";
            for (auto check: m_commands[location].commands) {
                uint64_t valueToCheck;
                switch (check.what[0]) {
                    case 'x':
                        valueToCheck = xmas.x;
                        break;
                    case 'm':
                        valueToCheck = xmas.m;
                        break;
                    case 'a':
                        valueToCheck = xmas.a;
                        break;
                    case 's':
                        valueToCheck = xmas.s;
                        break;
                }
                bool moveForward = false;
                if (check.operate == ">" && valueToCheck > check.when) moveForward = true;
                if (check.operate == "<" && valueToCheck < check.when) moveForward = true;
                if (moveForward) {
                    newLocation = check.where;
                    break;
                }
            }
            if (newLocation == "") newLocation = m_commands[location].noMatch;
            location = newLocation;

        }
        if (location == "A") m_acceptA.emplace_back(xmas);
        if (location == "R") m_reject.emplace_back(xmas);
    }
    for (auto accepted: m_acceptA) {
        m_resultA += accepted.sum();
    }

}

std::string Day::xmas_checker(tCommand &cmd, tXMAS_B &orig, tXMAS_B &other, tMAX_MIN &origField, tMAX_MIN &newField) {
    if ((cmd.operate == ">" && origField.min > cmd.when) || (cmd.operate == "<" && origField.max < cmd.when)) {
        return cmd.where;
    }
    if (cmd.operate == ">") {
        if (cmd.when < origField.min || origField.max >= cmd.when) return orig.pile;
        newField.max = cmd.when;
        origField.min = cmd.when + 1;
        m_xmasB.emplace_back(other);
        return cmd.where;
    } else if (cmd.operate == "<") {
        if (cmd.when > origField.max || origField.min >= cmd.when) return orig.pile;
        newField.min = cmd.when;
        origField.max = cmd.when - 1;
        m_xmasB.emplace_back(other);
        return cmd.where;
    } else {
        ExitIfReachedWithMessage(cmd.failReasonOperator());
    }
}

void Day::RunB() {
    std::queue<std::tuple<std::string, tMAX_MIN, tMAX_MIN, tMAX_MIN, tMAX_MIN>> q;
    std::vector<std::tuple<tMAX_MIN, tMAX_MIN, tMAX_MIN, tMAX_MIN>> results;
    q.push(std::make_tuple("in", tMAX_MIN{4000, 1}, tMAX_MIN{4000, 1}, tMAX_MIN{4000, 1}, tMAX_MIN{4000, 1}));
    tMAX_MIN tmp = tMAX_MIN{0, 0};
    std::reference_wrapper<tMAX_MIN> ref = std::ref(tmp);
    while (!q.empty()) {
        auto [section, x, m, a, s] = q.front();
        q.pop();
        if (section == "R") {
            continue;
        }
        if (section == "A") {
            results.push_back(std::make_tuple(x, m, a, s));
            continue;
        }


        for (tCommand command: m_commands[section].commands) {
            switch (command.what[0]) {
                case 'x':
                    ref = std::ref(x);
                    break;
                case 'm':
                    ref = std::ref(m);
                    break;
                case 'a':
                    ref = std::ref(a);
                    break;
                case 's':
                    ref = std::ref(s);
                    break;
                default: ExitIfReachedWithMessage(command.what[0]);
            }
            auto &field = ref.get();

            if (command.operate == "<") {
                if (field.max < command.when) {
                    q.push(make_tuple(command.where, x, m, a, s));
                } else if (field.min < command.when) {
                    tMAX_MIN tmpField = field;
                    field.max = command.when - 1;
                    q.push(make_tuple(command.where, x, m, a, s));
                    field.min = command.when;
                    field.max = tmpField.max;
                }
            } else {
                if (field.min > command.when) {
                    q.push(make_tuple(command.where, x, m, a, s));
                } else if (field.max > command.when) {
                    auto tmpField = field;
                    field.min = command.when + 1;
                    q.push(make_tuple(command.where, x, m, a, s));
                    field.min = tmpField.min;
                    field.max = command.when;
                }
            }

        }
        if (m_commands[section].noMatch != "R") {
            q.push(make_tuple(m_commands[section].noMatch, x, m, a, s));
        }
    }
    m_resultB = 0;
    for (auto [x, m, a, s]: results) {
        if (x.max < x.min || m.max < m.min || a.max < a.min || s.max < s.min) ExitIfReached();
        m_resultB += (x.max - x.min + 1) * (m.max - m.min + 1) * (a.max - a.min + 1) * (s.max - s.min + 1);
    }
}


void Day::Report() {
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}
