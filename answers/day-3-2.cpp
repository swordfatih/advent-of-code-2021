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
    auto most = read_file<std::string>("inputs/input-");
    auto least = most;

    const int bit_size = most[0].size();

    for(int i = 0; i < bit_size; ++i) {
        int most_count = 0;
        int least_count = 0;

        for (auto& token : most)
            if(token[i] == '1')
                most_count++;

        for (auto& token : least)
            if(token[i] == '1')
                least_count++;

        char most_bit = '0' + (most_count >= most.size() - most_count);
        char least_bit = '0' + (least_count < least.size() - least_count);

        for(int j = 0; j < most.size();) {
            if(most[j][i] != most_bit)
                most.erase(most.begin() + j);
            else 
                j++;
        }

        for(int j = 0; j < least.size();) {
            if(least[j][i] != least_bit)
                least.erase(least.begin() + j);
            else 
                j++;
        }
    }

    std::cout << most[0] << ' ' << least[0] << std::endl;

    std::cout << std::bitset<12>(most[0]).to_ulong() * std::bitset<12>(least[0]).to_ulong() << std::endl;
}