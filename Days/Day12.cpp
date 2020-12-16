#include "Day12.h"


void Day12::solve() {

    int part1 = 0;
    int part2 = 0;

    std::ifstream inputstream;
    inputstream.open("..\\Input\\day12.txt");

    std::pair<int,int>location = {0,0};
    std::pair<int,int>location2 = {0,0};
    std::pair<int,int>waypoint = {10,1};

    int direction = 1;

    while(!inputstream.eof()) {

        char command;
        int value;

        inputstream >> command >> value;

        switch(command) {

            case 'N':
                Day12::move(location,0,value);
                Day12::move(waypoint,0,value);
                break;
            case 'S':
                Day12::move(location,2,value);
                Day12::move(waypoint,2,value);
                break;
            case 'E':
                Day12::move(location,1,value);
                Day12::move(waypoint,1,value);
                break;
            case 'W':
                Day12::move(location,3,value);
                Day12::move(waypoint,3,value);
                break;
            case 'L':
                    direction -= value/90;
                    if(direction < 0)
                        direction += 4;
                    rotate(waypoint,command,value);
                break;
            case 'R':
                direction += value/90;
                if(direction > 3)
                    direction -= 4;
                rotate(waypoint,command,value);
                break;
            case 'F':
                Day12::move(location,direction,value);
                location2.first += waypoint.first * value;
                location2.second += waypoint.second * value;
                break;
            default:;
        }

    }

    part1 = std::abs(location.first) + std::abs(location.second);
    part2 = std::abs(location2.first) + std::abs(location2.second);

    std::cout << "The result to part 1 is: " << part1 << "!\n";
    std::cout << "The result to part 2 is: " << part2 << "!\n";

}

void Day12::move(std::pair<int, int> &loc, int com, int mult) {

    switch(com) {

        case 0:
            loc.second += mult;
            break;
        case 1:
            loc.first += mult;
            break;
        case 2:
            loc.second -= mult;
            break;
        case 3:
            loc.first -= mult;
            break;
        default:;
    }
}

void Day12::rotate(std::pair<int, int> &way, char com, int mult) {
    switch(com) {

        case 'R':
                for(int i = 0; i < mult/90; ++i) {
                    int arch = 0 - way.first;
                    way.first = way.second;
                    way.second = arch;
                }
            break;
        case 'L':
            for(int i = 0; i < mult/90; ++i) {
                int arch = 0 - way.second;
                way.second = way.first;
                way.first = arch;
            }
            break;
        default:;
    }
 }