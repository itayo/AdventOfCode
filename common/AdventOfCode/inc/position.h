#ifndef ADVENTOFCODE_POSITION_H
#define ADVENTOFCODE_POSITION_H

#include <vector>
#include <string>

namespace AoC {
    class position {
    public:
        position(int x, int y) : m_x(x), m_y(y) {
        }
        int X() {return m_x;}
        int Y() {return m_y;}
        private:
        int m_x = 0;
        int m_y = 0;

    };
}


#endif //ADVENTOFCODE_GRID2D_H
