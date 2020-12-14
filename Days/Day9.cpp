#include "Day9.h"


void Day9::solve() {

    long long part1 = 0;
    long long part2 = 0;

    std::deque<long long>queue1;
    std::deque<long long>queue2;

    std::ifstream inputstream;
    inputstream.open("..\\Input\\day9.txt");

    long long num;

    int cursor1 = 0;
    int cursor2 = 0;

    std::vector<long long>line;

    while(!inputstream.eof()) {
        long long l;
        inputstream >> l;
        line.emplace_back(l);
    }

    for(int i = 0 ; i < 25; ++i) {
        num = line[cursor1];
        ++cursor1;
        queue1.emplace_back(num);
    }

    for(int i = 0 ; i < 25; ++i) {
        num = line[cursor2];
        ++cursor2;
        queue2.emplace_back(num);
    }

    while(cursor1 < line.size()) {

        bool passed = false;
        num = line[cursor1];
        ++cursor1;

        for(int i = 0 ; i < 25; ++i) {
            for(int j = 0 ; j < 25; ++j) {
                if(i == j)
                    continue;

                if(queue1[i] + queue1[j] == num)
                    passed = true;
            }
        }

        if(!passed) {
            part1 = num;
            break;
        } else {
            queue1.pop_front();
            queue1.emplace_back(num);
        }
    }
    while(true) {

        part2 = 0;
        for(auto &e : queue2)
            part2 += e;

        if(part1 == part2)
            break;

        if(part2 > part1) {
            queue2.pop_front();
        } else {
            queue2.emplace_back(line[cursor2]);
            ++cursor2;
        }
    }

    std::sort(queue2.begin(),queue2.end());

    part2 = queue2.front() + queue2.back();

    std::cout << "The result to part 1 is: " << part1 << "!\n";
    std::cout << "The result to part 2 is: " << part2 << "!\n";

}
