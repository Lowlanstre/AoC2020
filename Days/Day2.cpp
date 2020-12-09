#include "Day2.h"

void Day2::solve() {

    int part1 = 0;
    int part2 = 0;

    std::ifstream inputstream;
    inputstream.open("..\\Input\\day2.txt");

    /* Questionably named variables */
    int good;
    int lower;
    int higher;
    int index;
    char garbage;
    char pass;
    char test;
    bool found;

    while(!inputstream.eof()) {

        inputstream >> lower >> garbage >> higher >> pass >> garbage;

        good = 0;
        index = 0;
        found = false;

        while (inputstream >> test) {

            ++index;
            if(index == lower || index == higher) {
                if (test == pass) {
                    if(found) {
                        part2 -= 2;
                    }
                    ++part2;
                    found = true;
                }
            }

            if (test == pass)
                ++good;

            char n = inputstream.peek();
            if (n == char(10)) {
                break;
            }
        }
        if(lower <= good && good <= higher) {
            ++part1;
        }
    }

    std::cout << "The result to part 1 is: " << part1 << "!\n";
    std::cout << "The result to part 2 is: " << part2 << "!\n";

}
