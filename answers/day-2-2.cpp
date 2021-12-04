#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>

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
    auto tokens = read_file<std::string>("inputs/input-2");

    int x = 0;
    int depth = 0;
    int aim = 0;

    std::string* direction = nullptr;
    for (auto& token : tokens)
    {
        if(direction == nullptr)
            direction = &token;
        else {
            int unit = std::stoi(token);

            if(*direction == "forward") {
                x += unit;
                depth += aim * unit;
            }
            else if(*direction == "up") {
                aim -= unit;
            }
            else if(*direction == "down") {
                aim += unit;
            }

            direction = nullptr;
        }
    }

    std::cout << x * depth << std::endl;
}