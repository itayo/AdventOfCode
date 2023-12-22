#include <iostream>
#include "day.h"

void Day::PrepareData() {

}

void Day::Dig(std::vector<tInput> &m_inputs) {
    std::vector<AoC::Vector2D> result;
    std::map<AoC::Vector2D::tFacing, AoC::Vector2D> directions = {{AoC::Vector2D::tFacing::EAST,  {1,  0}},
                                                                  {AoC::Vector2D::tFacing::WEST,  {-1, 0}},
                                                                  {AoC::Vector2D::tFacing::NORTH, {0,  -1}},
                                                                  {AoC::Vector2D::tFacing::SOUTH, {0,  1}}};
    AoC::Vector2D current{0, 0};
    result.emplace_back(current);
    int64_t lace = 0;
    int64_t size = 0;
    for (tInput input: m_inputs) {
        current += directions.at(input.dir) * input.steps;
        result.emplace_back(current);
        size += input.steps;
    }
    int64_t area = 0;
    //result.emplace_back(result[0]);
    for(uint64_t i=1;i< result.size();++i )
    for(AoC::Vector2D curr: result) {
        int64_t a = result[i-1].X()*result[i].Y();
        int64_t b = result[i-1].Y()*result[i].X();
        area += a-b;
    }
    area = std::llabs(area)/2;
    auto halfSize = size/2;
    m_resultA = (area-halfSize+1);



}


void Day::RunA(bool secondData) {
    Dig(m_commands);
}


void Day::RunB() {

}

void Day::Report() {
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}