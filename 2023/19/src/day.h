#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include "AoC/aoc.h"
#include <unordered_map>
#include <list>
#include "AoC/Grid2D.h"

class Day {
public:
    struct tXMAS_A {
        tXMAS_A(uint64_t ix, uint64_t im, uint64_t ia, uint64_t is) : x(ix), m(im), a(ia), s(is) {};
        const uint64_t x;
        const uint64_t m;
        const uint64_t a;
        const uint64_t s;
        std::string pile = "in";

        uint64_t sum() { return x + m + a + s; }
    };

    struct tMAX_MIN {
        uint64_t max = 4000;
        uint64_t min = 1;
    };
    struct tXMAS_B {
        static const size_t LOW = 0;
        static const size_t HI = 1;
        tMAX_MIN x;
        tMAX_MIN m;
        tMAX_MIN a;
        tMAX_MIN s;
        std::string pile = "in";
    };

    enum tOperator {
        less = 0,
        more = 1
    };

    struct tCommand {
        std::string what;
        std::string operate;
        uint64_t when;
        std::string where;

        std::string failReasonOperator() {
            return "Unexpected Operator: " + operate;
        }

    };

    struct tCommands {
        std::vector<tCommand> commands;
        std::string noMatch;
    };


    Day(std::vector<std::string> data)
            : m_resultA(0), m_resultB(0), m_data(data) {
        std::vector<std::vector<std::string>> tmpData(2);
        int pos = 0;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i].empty()) {
                pos++;
                continue;
            }
            std::string line = data[i];

            if (pos == 0) {
                aoc.StringReplace(line, {
                        {"{", ","},
                        {"}", ""}
                });
                tCommands cmds;
                auto vec = aoc.StringSplit(line, ',');
                cmds.noMatch = vec.back();
                for (int j = 1; j < vec.size() - 1; ++j) {
                    auto b = aoc.StringSplit(vec[j], ':');
                    tCommand cmd;
                    cmd.what = b[0][0];
                    cmd.operate = b[0][1];
                    cmd.when = std::stoull(b[0].substr(2, b[0].length() - 2));
                    cmd.where = b[1];
                    cmds.commands.emplace_back(cmd);
                }
                m_commands[vec[0]] = cmds;
            } else {
                aoc.StringReplace(line, {
                        {"{", ""},
                        {"}", ""}}
                );
                auto vec = aoc.StringSplit(line, ',');
                uint64_t x, m, a, s;
                for (int j = 0; j < vec.size(); ++j) {

                    switch (vec[j][0]) {
                        case 'x':
                            x = std::stoull(vec[j].substr(2, vec[j].size() - 2));
                            break;
                        case 'm':
                            m = std::stoull(vec[j].substr(2, vec[j].size() - 2));
                            break;
                        case 'a':
                            a = std::stoull(vec[j].substr(2, vec[j].size() - 2));
                            break;
                        case 's':
                            s = std::stoull(vec[j].substr(2, vec[j].size() - 2));
                            break;
                    }
                }
                m_xmasA.emplace_back(x, m, a, s);

            }
        }
        tXMAS_B b;
        m_xmasB.emplace_back(b);
    }

    void PrepareData();

    void RunA(bool secondData = false);

    void RunB();

    void Report();

    uint64_t ResultA() { return m_resultA; }

    uint64_t ResultB() { return m_resultB; }


private:
    std::string xmas_checker(tCommand &cmd, tXMAS_B &orig, tXMAS_B &other, tMAX_MIN &origField, tMAX_MIN &newField);

    std::unordered_map<std::string, tCommands> m_commands;
    std::vector<tXMAS_A> m_acceptA;
    std::vector<tXMAS_A> m_reject;
    std::vector<tXMAS_A> m_xmasA;
    std::vector<tXMAS_B> m_xmasB;

    AoC::AoC aoc;
    const std::vector<std::string> m_data;
    uint64_t m_resultA;
    uint64_t m_resultB;
};

#endif //ADVENTOFCODE_DAY_H
