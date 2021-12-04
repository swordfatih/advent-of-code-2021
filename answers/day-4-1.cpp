#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <array>
#include <sstream>
#include <bitset>
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

bool board_is_winner(const std::vector<std::vector<int>>& board) {
    for(auto& row : board) {
        bool row_winner = true;

        for(auto& value : row) {
            
            if(value != -1)
                row_winner = false;
        }
        
        if(row_winner) {
            return true;
        }
    }

    
    for(int i = 0; i < board[0].size(); ++i) {
        bool col_winner = true;

        for(auto&& row : board) 
            if(row[i] != -1)
                col_winner = false;

        if(col_winner) {
            return true;
        }
    }

    return false;
}

int board_sum(const std::vector<std::vector<int>>& board) {
    int sum = 0;

    for(auto& row : board) {
        for(auto& value : row) {  
            if(value != -1)
                sum += value;
        }
    }

    return sum;
}

int main()
{
    auto lines = read_lines("inputs/input-4");
   
    std::replace(lines[0].begin(), lines[0].end(), ',', ' ');
    std::vector<int> drawns = read_stream<int>(lines[0]);
    
    lines.erase(lines.begin());

    for(int i = 0; i < lines.size(); ) {
        if(lines[i].size() == 0)
            lines.erase(lines.begin() + i);
        else
            i++;
    }

    std::vector<std::vector<std::vector<int>>> boards;
    for(int i = 0; i < lines.size() / 5; ++i) {
        boards.emplace_back();
        auto&& board = boards[boards.size() - 1];

        for(int j = 0; j < 5; ++j)
            board.push_back(read_stream<int>(lines[i * 5 + j]));
    }

    for(auto& drawn : drawns) {
        for(auto& board : boards) {
            for(auto& row : board) {
                for(auto& value : row) 
                    if(value == drawn)
                        value = -1;
            }

            if(board_is_winner(board)) {
                auto sum = board_sum(board);
                std::cout << "winner: " << drawn << " sum: " << sum << " mul: " << drawn * sum << std::endl;
                return 0;
            }
        }
    }
}