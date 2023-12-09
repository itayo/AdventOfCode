#ifndef ADVENTOFCODE_GRID2D_H
#define ADVENTOFCODE_GRID2D_H

#include <vector>
#include <string>
#include "position.h"
#include "Assertion.h"

namespace AoC {

    template<class tType>
    class Grid2D {
    public:
        Grid2D(int p_rows, int p_cols) :
                m_rows(p_rows), m_columns(p_cols), m_cells(p_rows * p_cols) {

        };

        Grid2D(int p_rows, int p_cols, tType initValue) :
                m_rows(p_rows), m_columns(p_cols), m_cells(p_rows * p_cols, initValue) {

        };

        Grid2D() : Grid2D(0, 0) {}

        int Columns() { return m_columns; }

        int Rows() { return m_rows; }

        bool Exists(int p_row, int p_column) {
            return
                    p_row < m_rows &&
                    p_column < m_columns &&
                    p_row >= 0 && p_column >= 0;
        }

        bool Exists(position p_position) { return Exists(p_position.X(), p_position.Y()); }

        tType Get(int p_row, int p_column) {
            if (Exists(p_row, p_column)) {
                return m_cells[(m_columns * p_row) + p_column];
            }
            return tType();
        }

        tType Get(position p_position) { return Get(p_position.X(), p_position.Y()); }

        void Reset(std::vector<std::string> p_defaultData) {
            m_cells.clear();
            m_rows = p_defaultData.size();
            m_columns = p_defaultData[0].size();
            for (std::string row: p_defaultData) {
                for (char character: row)
                    m_cells.template emplace_back(character);
            }
        }

        void Resize(int p_rows, int p_columns) {
            Grid2D<tType> grid(p_rows, p_columns);
            *this = std::move(grid);
        }

        void Set(int p_row, int p_column, tType p_value) {
            if (Exists(p_row, p_column)) {
                m_cells[(m_columns * p_row) + p_column] = p_value;
            }
        }

        void Set(position p_position, tType p_value) {
            Set(p_position.X(), p_position.Y(), p_value);
        }

        void SetAll(tType value) {
            for (auto &cell: m_cells) {
                cell = value;
            }
        }

        void SetRow(int p_row, tType p_value) {
            for (int column = 0; column < m_columns; ++column) {
                Set(p_row, column, p_value);
            }
        }

        void SetColumn(int p_column, tType p_value) {
            for (int row = 0; row < m_rows; ++row) {
                Set(row, p_column, p_value);
            }
        }

        int count_if(tType value) {
            return std::count_if(m_cells.begin(), m_cells.end(), [&value](tType i) { return value == i; });
        }

        void Print() {
            for(int row = 0; row < m_rows; ++row) {
                for(int cols =0 ; cols < m_columns;++cols)
                {
                    std::cout << Get(row,cols);
                }
                std::cout << std::endl;
            }

        }

    private:
        int m_rows = 0;
        int m_columns = 0;
        std::vector<tType> m_cells;
    };
}


#endif //ADVENTOFCODE_GRID2D_H
