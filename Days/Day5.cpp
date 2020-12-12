#include "Day5.h"

void Day5::solve() {

    int part1 = 0;
    int part2 = 0;

    std::ifstream inputstream;
    inputstream.open("..\\Input\\day5.txt");

    std::vector<int>passes;

    int curr;

    while(!inputstream.eof()) {
        std::string pass;
        std::getline(inputstream,pass);

        int lower = 0;
        int higher = 127;
        int left = 0;
        int right = 7;

        for(auto &c : pass) {
            switch(c){
                case 'F':
                    higher -= ((higher-lower)+1)/2;
                    break;
                case 'B':
                    lower += ((higher-lower)+1)/2;
                    break;
                case 'R':
                    left += ((right-left)+1)/2;
                    break;
                case 'L':
                    right -= ((right-left)+1)/2;
                    break;
                default:;
            }
        }
        curr = lower*8 + left;
        passes.push_back(curr);
        if(curr > part1)
            part1 = curr;
    }

    std::sort(passes.begin(),passes.end());

    for(int i = 1; i < passes.size(); ++i) {
        if(passes[i]-2 == passes[i-1])
            part2 = passes[i]-1;
    }

    std::cout << "The result to part 1 is: " << part1 << "!\n";
    std::cout << "The result to part 2 is: " << part2 << "!\n";

}
