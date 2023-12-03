#ifndef ADVENTOFCODE_GRID2D_H
#define ADVENTOFCODE_GRID2D_H

#include <vector>
#include <string>
#include "position.h"

namespace AoC {

    template<class tType>
    class Grid2D {
    public:
        Grid2D(int rows = 0, int cols = 0) : m_rows(rows), m_cols(cols) {
            m_cells = std::vector<std::vector<tType>> (rows, std::vector<tType>(cols));
        };

        bool Exists(int row, int col) { return row < m_rows && col << m_cols && row >= 0 && col >=0; }

        bool Exists(position pos) { return Exists(pos.X(), pos.Y()); };

        tType Get(int row, int col) {
            if (Exists(row, col)) {
                return m_cells[row][col];
            }
            return tType();
        }

        tType Get(position pos) { return Get(pos.X(), pos.Y()); };

        void Set(int row, int col, tType val) {
            if (Exists(row, col)) {
                m_cells[row][col] = val;
            }
        }

    private:
        int m_rows = 0;
        int m_cols = 0;
        std::vector<std::vector<tType>> m_cells;
    };
}


#endif //ADVENTOFCODE_GRID2D_H
