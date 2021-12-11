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

    std::sort(tokens.begin(), tokens.end());
    int mediane = tokens[std::floor((tokens.size() - 1) / 2)];

    int counter = 0;
    for(auto&& token: tokens)
        counter += std::abs(token - mediane);

    std::cout << counter << std::endl;
}