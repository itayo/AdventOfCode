#include <iostream>
#include "day.h"
#include <string>
#include <algorithm>

Day::Day(std::vector<std::string> data) : m_resultA(0), m_resultB(0), m_data(data) {
}

struct dataField {
    dataField(std::string word, std::string replace): m_word(word), m_replace(replace){   }
    std::string m_word;
    std::string m_replace;
    std::vector<size_t> m_pos;
};

std::string Day::wordToInt(std::string data)
{
    std::vector<dataField> words;
    std::vector<std::string> tmp = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
    for(uint i = 0; i< tmp.size();i++) {
        words.push_back(dataField(tmp[i], std::to_string(i)));
    }
    std::transform(data.begin(), data.end(), data.begin(),[](unsigned char c){ return std::toupper(c); });
    for(uint i=0; i < words.size(); i++) {
        size_t pos = 0;
        while ((pos = data.find(words[i].m_word, pos)) != std::string::npos) {
            words[i].m_pos.push_back(pos);
            pos++;
        }
    }
    for(auto word : words) {
        for(size_t p: word.m_pos) {
            data.replace(p,1,word.m_replace);
        }
    }
    return data;
}


int Day::commonCalc(std::string data) {
    std::string numbers;
    std::string result;
    for(char a :data) {
        if (isdigit(a)) {
            numbers += a;
        }
    }
    if(numbers.length() == 1) {
        result = numbers[0];
        result+= numbers[0];
    }
    else if (numbers.length() == 0) {
        return 0;
    }
    else {
        result = numbers[0];
        result += numbers.back();
    }
    return std::stoi(result);
}

void Day::runA(bool secondData) {

    for(auto line: m_data)
    {

            m_resultA += commonCalc(line);
    }
}

void Day::runB() {
    for(auto line: m_data)
    {
        std::string data = wordToInt(line);
        m_resultB += commonCalc(data);
    }
}

void Day::report() {
    std::cout << "2021-01-1: " << m_resultA << std::endl;
    std::cout << "2021-01-2: " << m_resultB;
}