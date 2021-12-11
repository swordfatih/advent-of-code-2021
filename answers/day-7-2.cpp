#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstdint>
#include <cmath>

template <typename T>
std::vector<T> read_stream(std::string s) {
    std::stringstream stream(s);
    std::vector<T> tokens;
    
    T token;
    while(stream >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

std::vector<std::string> read_lines(std::string name) {
    std::ifstream read(name);

    std::vector<std::string> tokens;
    
    std::string token;
    while(std::getline(read, token)) {
        tokens.push_back(token);
    }

    return tokens;
}

template <typename T>
std::vector<T> read_stream(std::string s, char delimiter) {
    std::stringstream stream(s);
    std::vector<T> tokens;
    
    T token;
    while(stream >> token) {
        tokens.push_back(token);

        if(stream.peek() == delimiter) {
            char c;
            stream.read(&c, 1);
        } 
    }

    return tokens;
}

int main()
{
    auto&& lines = read_lines("inputs/input-7");

    auto&& tokens = read_stream<int>(lines[0], ',');

    int min = -1;
    for(int i = 0; i < 1000; ++i) {   
        int counter = 0;
        for(auto&& value: tokens) {
            int diff = std::abs(value - i);
            counter += (diff * (diff + 1)) / 2;
        }

        if(min == -1 || counter < min) {
            min = counter;
        }
    }

    std::cout << min << std::endl;
}