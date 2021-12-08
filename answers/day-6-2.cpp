#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstdint>

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
    auto&& lines = read_lines("inputs/input-6");
    auto&& tokens = read_stream<int>(lines[0], ',');

    std::vector<uint64_t> fishes; 

    for(int i = 0; i <= 8; ++i) 
        fishes.push_back(0);

    for(uint64_t token: tokens)
        fishes[token]++;

    for(int i = 0; i < 256; ++i) {
        uint64_t m = fishes[0];

        for(int j = 1; j <= 8; ++j) 
            fishes[j - 1] = fishes[j];

        fishes[6] += m; 
        fishes[8] = m;
    }

    uint64_t counter = 0;
    for(uint64_t count: fishes) {
        counter += count;
    }

    std::cout << "count: " << counter << std::endl;
}