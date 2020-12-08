#include "Day1.h"

void Day1::solve() {

    int part1 = 0;
    int part2 = 0;

    std::vector<int>nums;

    std::ifstream inputstream;
    inputstream.open("..\\Input\\day1.txt");

    while (!inputstream.eof()) {
        int input;
        inputstream >> input;
        nums.push_back(input);
    }

    /* Part 1 && Part 2*/

    for(int i = 0; i < nums.size(); ++i) {
        for(int j = 0; j < nums.size(); ++j) {
            for(int k = 0; k < nums.size(); ++k) {
                if (i == j || j == k || i == k || part2 != 0)
                    continue;
                if (nums[i] + nums[j] + nums[ k]== 2020)
                    part2 = nums[i] * nums[j] * nums[k];
            }
            if (i == j || part1 != 0)
                continue;
            if (nums[i] + nums[j] == 2020)
                part1 = nums[i] * nums[j];
        }
    }


    std::cout << "The result to part 1 is: " << part1 << "!\n";
    std::cout << "The result to part 2 is: " << part2 << "!\n";

}
