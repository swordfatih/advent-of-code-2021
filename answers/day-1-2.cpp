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
    auto tokens = read_file<int>("inputs/input-1");

    int counter = 0;
    std::deque<int*> lasts;

    for (auto& token : tokens)
    {
        if(lasts.size() < 3) {
            lasts.push_back(&token);
        }
        else {
            int last_sum = 0;

            for (auto last : lasts)
                last_sum += *last;

            lasts.pop_front();
            lasts.push_back(&token);

            int sum = 0;

            for (auto last : lasts)
                sum += *last;

            if(sum > last_sum)
                counter++;
        }
    }

    std::cout << counter << std::endl;
}