#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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
    auto tokens = read_file<int>("inputs/input-1");

    int counter = 0;
    int* last = nullptr;
    for (auto& token : tokens)
    {
        if(last != nullptr && token > *last) {
            counter++;
        }
        
        last = &token;
    }

    std::cout << counter << std::endl;
}