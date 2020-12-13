#include "Day6.h"

void Day6::solve() {

    int part1 = 0;
    int part2 = 0;

    std::ifstream inputstream;
    std::stringstream sstream;
    inputstream.open("..\\Input\\day6.txt");

    sstream << inputstream.rdbuf();

    std::set<char>unique;
    std::vector<std::set<char>>commonSets;
    std::string answers;

    bool commonAnswer = true;


    while(!sstream.eof()) {

        std::string answer;

        std::getline(sstream, answer);

        if (answer.empty()) {

            answers += " ";

            for(auto &c : answers)
                unique.emplace(c);

            part1 += unique.size()-1;

            answers.clear();
            unique.clear();

            for(auto &a : commonSets[0]) {
                for(auto &s : commonSets) {
                    if(s.find(a) == s.end()) {
                        commonAnswer = false;
                        break;
                    }
                }
                if(commonAnswer)
                    ++part2;
                commonAnswer = true;
            }
            commonSets.clear();
        } else {
            std::set<char>common;

            for(auto &c : answer)
                common.emplace(c);
            commonSets.push_back(common);
            answers += " " + answer;
        }
    }

    std::cout << "The result to part 1 is: " << part1 << "!\n";
    std::cout << "The result to part 2 is: " << part2 << "!\n";

}
