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
    auto&& lines = read_lines("inputs/input-test");

    std::vector<std::pair<std::vector<std::string>, std::vector<std::string>>> tokens;

    for(auto&& line: lines) {
        std::string input = line.substr(0, line.find('|') - 1);
        std::string output = line.substr(line.find('|') + 1);
        tokens.push_back(std::make_pair(read_stream<std::string>(input), read_stream<std::string>(output)));
    }

    int counter = 0;

    for(auto&& [inputs, outputs]: tokens) {
        std::string value;

        for(auto&& output: outputs) {
            int s = output.size();
        
            if(s == 2) 
                value += '1';
            else if(s == 3)
                value += '7';
            else if(s == 4)
                value += '4';
            else if(s == 7)
                value += '8';
        }

        counter += std::stoi(value);
    }

    std::cout << counter << std::endl;
}