#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>

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

void push(std::map<int, std::map<int, int>>& grid, std::string line) {
    int x1, y1, x2, y2;

    y1 = std::stoi(line.substr(0, line.find(',')));
    x1 = std::stoi(line.erase(0, line.find(',') + 1).substr(0, line.find('-') - 1));
    y2 = std::stoi(line.erase(0, line.find('>') + 1).substr(0, line.find(',')));
    x2 = std::stoi(line.erase(0, line.find(',') + 1));
    
    if(x1 == x2) {
        for(int y = std::min(y1, y2); y <= std::max(y1, y2); ++y) {
            if(grid.find(x1) == grid.end() || grid[x1].find(y) == grid[x1].end())
                grid[x1][y] = 0;
            grid[x1][y]++;
        }
    } 
    else if(y1 == y2) {
        for(int x = std::min(x1, x2); x <= std::max(x1, x2); ++x) {
            if(grid.find(x) == grid.end() || grid[x].find(y1) == grid[x].end())
                grid[x][y1] = 0;
            grid[x][y1]++;      
        }
    } 
}

int main()
{
    auto lines = read_lines("inputs/input-5");

    std::map<int, std::map<int, int>> grid;

    for(auto&& line : lines) {
        push(grid, std::move(line));
    }

    int counter = 0;
    for(auto&& [x, y_grid] : grid) {
        for(auto&& [y, count] : y_grid) {
            if(count >= 2)
                counter++;
        }
    }

    // for(int i = 0; i < 10; ++i) {
    //     for(int j = 0; j < 10; ++j) {
    //         if(grid.find(i) == grid.end() || grid[i].find(j) == grid[i].end())
    //             std::cout << '.';
    //         else
    //             std::cout << grid[i][j];
    //     }

    //     std::cout << std::endl;
    // }

    std::cout << counter << std::endl;
}