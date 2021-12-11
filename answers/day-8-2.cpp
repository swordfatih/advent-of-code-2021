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

std::string difference(std::string first, std::string second) {
    std::string concat = first + second;
    std::string result;

    for(int i = 0; i < concat.size(); ++i)
        if(first.find(concat[i]) == std::string::npos || second.find(concat[i]) == std::string::npos)
            result += concat[i];

    return result;
}

int main()
{
    auto&& lines = read_lines("inputs/input-8");

    std::vector<std::pair<std::vector<std::string>, std::vector<std::string>>> tokens;

    for(auto&& line: lines) {
        std::string input = line.substr(0, line.find('|') - 1);
        std::string output = line.substr(line.find('|') + 1);
        tokens.push_back(std::make_pair(read_stream<std::string>(input), read_stream<std::string>(output)));
    }

    int counter = 0;

    for(auto&& [inputs, outputs]: tokens) {
        std::string value;
        std::string joined;

        std::vector<std::string> combinaisons(10);
        std::map<char, char> matchs;

        for(auto&& input: inputs) {
            int s = input.size();

            if(s == 2) 
                combinaisons[1] = input;
            else if(s == 3)
                combinaisons[7] = input;
            else if(s == 4)
                combinaisons[4] = input;
            else if(s == 7)
                combinaisons[8] = input;
        }

        for(int i = 0; i < inputs.size(); ++i) {
            if(inputs[i].size() == 6) {
                if(difference(inputs[i], combinaisons[4]).size() == 2)
                    combinaisons[9] = inputs[i];
                else if(difference(inputs[i], combinaisons[1]).size() == 4)
                    combinaisons[0] = inputs[i];
                else 
                    combinaisons[6] = inputs[i];
            }
        }

        matchs['a'] = difference(combinaisons[7], combinaisons[1])[0];
        matchs['g'] = difference(difference(combinaisons[9], combinaisons[4]), std::string{matchs['a']})[0];
        matchs['e'] = difference(combinaisons[9], combinaisons[8])[0];
        matchs['c'] = difference(combinaisons[6], combinaisons[8])[0];
        matchs['d'] = difference(combinaisons[0], combinaisons[8])[0];
        matchs['f'] = difference(combinaisons[1], std::string{matchs['c']})[0];

        std::string all;
        for(auto&& match: matchs)
            all += match.second;

        matchs['b'] = difference(combinaisons[8], all)[0];

        for(auto&& output: outputs) {
            joined += output + ' ';

            int s = output.size();
        
            if(s == 2) 
                value += '1';
            else if(s == 3)
                value += '7';
            else if(s == 4)
                value += '4';
            else if(s == 7)
                value += '8';
            else if(s == 5) {
                if(output.find(matchs['f']) == std::string::npos)
                    value += '2';
                else if(output.find(matchs['b']) == std::string::npos)
                    value += '3';
                else    
                    value += '5';
            }
            else if(s == 6) {
                if(output.find(matchs['d']) == std::string::npos)
                    value += '0';
                else if(output.find(matchs['e']) != std::string::npos)
                    value += '6';
                else    
                    value += '9';
            }
        }

        std::cout << joined << ": " << value << std::endl;
        counter += std::stoi(value);
    }

    std::cout << counter << std::endl;
}