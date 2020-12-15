#include "Day11.h"


void Day11::solve() {

    int part1 = 0;
    int part2 = 0;

    std::ifstream inputstream;
    inputstream.open("..\\Input\\day11.txt");

    std::vector<std::vector<char>>grid;
    std::vector<std::vector<char>>gridCopy;
    std::vector<std::vector<char>>gridFar;
    std::vector<std::vector<char>>gridCopyFar;

    std::vector<std::pair<int,int>>offsets;

    offsets.emplace_back(-1,-1);
    offsets.emplace_back(-1,0);
    offsets.emplace_back(-1,1);
    offsets.emplace_back(0,-1);;
    offsets.emplace_back(0,1);
    offsets.emplace_back(1,-1);
    offsets.emplace_back(1,0);
    offsets.emplace_back(1,1);


    while(!inputstream.eof()) {

        std::string row;

        std::getline(inputstream,row);

        std::vector<char>rowV;

        for(auto &c : row)
            rowV.emplace_back(c);
        grid.emplace_back(rowV);
    }

    gridFar = grid;

    while(true) {

        gridCopy = grid;
        gridCopyFar = gridFar;

        for(int x = 0; x < grid.size(); ++x) {
            for(int y = 0; y < grid[x].size(); ++y) {

                if(gridCopy[x][y] == '.')
                    continue;

                int neighbors = 0;
                int neighborsFar = 0;

                for(auto &o : offsets) {

                    if(x+o.first < gridCopy.size() && x+o.first >= 0 && y+o.second >= 0 && y+o.second < gridCopy[x].size()) {
                           if(gridCopy[x+o.first][y+o.second] == '#') {
                               ++neighbors;
                           }
                    }

                    for (int r = 1;; ++r) {

                        if (x + (o.first * r) < gridCopyFar.size() && x + (o.first * r) >= 0 && y + (o.second * r) >= 0 &&
                            y + (o.second * r) < gridCopyFar[x].size()) {
                            if (gridCopyFar[x + (o.first*r)][y + (o.second*r)] == '#') {
                                ++neighborsFar;
                                break;
                            }
                            if (gridCopyFar[x + (o.first*r)][y + (o.second*r)] == 'L') {
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                }

                if(gridCopy[x][y] == 'L' && neighbors == 0)
                    grid[x][y] = '#';
                else if(gridCopy[x][y] == '#' && neighbors >= 4)
                    grid[x][y] = 'L';
                if(gridCopyFar[x][y] == 'L' && neighborsFar == 0)
                    gridFar[x][y] = '#';
                else if(gridCopyFar[x][y] == '#' && neighborsFar >= 5)
                    gridFar[x][y] = 'L';
            }
        }

        if(gridCopy == grid && gridCopyFar == gridFar)
            break;
    }


    for(auto &v : grid) {
        for(auto &e : v) {
            if(e == '#')
                ++part1;
        }
    }

    for(auto &v : gridFar) {
        for(auto &e : v) {
            if(e == '#')
                ++part2;
        }
    }

    std::cout << "The result to part 1 is: " << part1 << "!\n";
    std::cout << "The result to part 2 is: " << part2 << "!\n";

}
