#ifndef ADVENTOFCODE_VECTOR2D_H
#define ADVENTOFCODE_VECTOR2D_H

#include <vector>
#include <string>

namespace AoC {
    class Vector2D {
    public:
        enum tFacing {
            NORTH = 0,
            EAST = 1,
            SOUTH = 2,
            WEST = 3
        };

        Vector2D(int p_x, int p_y) : m_x(p_x), m_y(p_y) {
        }

        Vector2D(int p_x, int p_y, tFacing p_facing) : m_x(p_x), m_y(p_y), m_facing(p_facing) {
        }

        void X(int p_x) { m_x = p_x; }

        int X() { return m_x; }

        void Y(int p_y) { m_y = p_y; }

        int Y() { return m_y; }

        void TurnLeft() { m_facing = static_cast<tFacing>((m_facing + 3) % (WEST + 1)); }

        void TurnRight() { m_facing = static_cast<tFacing>((m_facing + 1) % (WEST + 1)); }

        void GoForward() {
            switch (m_facing) {
                case NORTH:
                    return GoNorth();
                case EAST:
                    return GoEast();
                case SOUTH:
                    return GoSouth();
                case WEST:
                    return GoWest();
            }

        }

        void GoNorth() { m_y--; }

        void GoEast() { m_x++; }

        void GoSouth() { m_y++; }

        void GoWest() { m_x--; }

        tFacing IsFacing() {return m_facing;}

        void Print() {
            std::cout << "X=" << m_x << " Y=" << m_y << " Facing=" << m_facing << std::endl;
        }
        std::string Cord()
        {
            std::string ret = "(";
            ret += std::to_string(m_x);
            ret += ",";
            ret += std::to_string(m_y);
            ret += ")";
            return ret;
        }

    private:
        tFacing m_facing = tFacing::NORTH;
        int m_x = 0;
        int m_y = 0;

    };
}


#endif //ADVENTOFCODE_GRID2D_H
