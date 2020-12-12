#include "Day3.h"

void Day3::solve() {

    int part1 = 0;
    long long part2 = 1;

    int i = 0;
    int j = 0;

    std::ifstream inputstream;
    inputstream.open("..\\Input\\day3.txt");

    std::vector<std::vector<char>>map;
    std::vector<std::pair<int,int>>slopes;
    slopes.emplace_back(1,1);
    slopes.emplace_back(5,1);
    slopes.emplace_back(1,2);
    slopes.emplace_back(7,1);
    slopes.emplace_back(3,1);

    while(!inputstream.eof()) {

        std::string line;
        std::getline(inputstream,line);

        std::vector<char>row;

        for(char c : line) {
            row.push_back(c);
        }

        map.push_back(row);

    }

    for(auto s : slopes) {

        part1 = 0;
        i = 0;
        j = 0;

        while (j < map.size() - 1) {
            i += s.first;
            j += s.second;

            if (i > map[j].size() - 1) {
                i -= map[j].size();
            }

            if (map[j][i] == '#')
                ++part1;
        }
        part2 *= part1;
    }

    std::cout << "The result to part 1 is: " << part1 << "!\n";
    std::cout << "The result to part 2 is: " << part2 << "!\n";

}
