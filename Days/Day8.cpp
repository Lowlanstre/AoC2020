#include "Day8.h"


void Day8::solve() {

    int part1 = 0;
    long long part2 = 0;

    std::ifstream inputstream;
    inputstream.open("..\\Input\\day8.txt");

    std::vector<std::pair<std::string,int>>instructions;

    while(!inputstream.eof()) {

        std::string instruction;
        int value;

        inputstream >> instruction >> value;
        instructions.emplace_back(instruction,value);

    }

    std::set<int>visited = {0};
    int cursor = 0;
    int acc = 0;
    bool ended = false;

    for(int i = 0; i <= instructions.size(); ++i) {

        while (true) {
            int last = visited.size();

            std::string instruction = instructions[cursor].first;
            if(cursor == i-1) {
                if (instruction == "nop")
                    cursor += instructions[cursor].second;
                else if (instruction == "acc") {
                    acc += instructions[cursor].second;
                    ++cursor;
                } else
                    ++cursor;
            } else {
                if (instruction == "nop")
                    ++cursor;
                else if (instruction == "acc") {
                    acc += instructions[cursor].second;
                    ++cursor;
                } else
                    cursor += instructions[cursor].second;
            }
            visited.emplace(cursor);

            if (cursor == instructions.size()) {
                ended = true;
                break;
            }
            if (last == visited.size()) {
                if(i == 0)
                    part1 = acc;
                cursor = 0;
                acc = 0;
                visited.clear();
                break;
            }
        }
        if(ended) {
            part2 = acc;
            break;
        }
    }

    std::cout << "The result to part 1 is: " << part1 << "!\n";
    std::cout << "The result to part 2 is: " << part2 << "!\n";

}
