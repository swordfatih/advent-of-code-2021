#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <array>
#include <bitset>

template <typename T>
std::vector<T> read_file(std::string name) {
    std::ifstream read(name);

    std::vector<T> tokens;
    
    T token;
    while(read >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

int main()
{
    auto tokens = read_file<std::string>("inputs/input-3");

    std::array<int, 12> bit_count;

    for (auto& count : bit_count)
        count = 0;

    for (auto& token : tokens)
        for(int i = 0; i < token.size(); ++i)
            if(token[i] == '1')
                bit_count[i]++;


    for (auto& count : bit_count)
        std::cout << count << ' ';
    std::cout << std::endl;

    std::bitset<12> gamma;

    const int size = tokens.size();
    for(int i = 0; i < bit_count.size(); ++i) {
        if(bit_count[i] > (size - bit_count[i]))
            gamma[bit_count.size() - i - 1] = 1;
        else
            gamma[bit_count.size() - i - 1] = 0;
    }

    std::cout << gamma.to_string() << std::endl;
    std::cout << gamma.to_ulong() * gamma.flip().to_ulong() << std::endl;
}