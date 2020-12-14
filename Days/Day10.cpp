#include "Day10.h"


void Day10::solve() {

    int part1 = 0;
    long long part2 = 0;

    std::ifstream inputstream;
    inputstream.open("..\\Input\\day10.txt");

    std::vector<std::pair<long long,int>>adapterways;
    std::vector<int>adapters = {0};
    std::vector<int>adapterD = {0,0,0};

    while(!inputstream.eof()) {

        int adapter;
        inputstream >> adapter;
        adapters.emplace_back(adapter);

    }

    std::sort(adapters.begin(),adapters.end());

    adapterways.reserve(adapters.size());

    for(auto e : adapters) {
        adapterways.emplace_back(0,e);
    }

    adapters.emplace_back(adapters.back()+3);

    for(int i = 0; i<adapters.size()-1;++i){

        ++adapterD[adapters[i+1]-adapters[i]-1];

    }

    part1 = adapterD[0]*adapterD[2];

    adapterways[0].first = 1;

    for(int i = 0; i < adapters.size(); ++i) {

        for(int j = 1 ; j <= 3 ; ++j) {
            if (i - j >= 0 && adapterways[i].second - adapterways[i - j].second <= 3) {
                adapterways[i].first += adapterways[i - j].first;
            }
        }
    }

    part2 = adapterways.back().first;

    std::cout << "The result to part 1 is: " << part1 << "!\n";
    std::cout << "The result to part 2 is: " << part2 << "!\n";

}
