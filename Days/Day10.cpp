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

        if(i-1 >= 0 && adapterways[i].second-adapterways[i-1].second <= 3) {
            adapterways[i].first += adapterways[i-1].first;
        }
        if(i-2 >= 0 && adapterways[i].second-adapterways[i-2].second <= 3) {
            adapterways[i].first += adapterways[i-2].first;
        }
        if(i-3 >= 0 && adapterways[i].second-adapterways[i-3].second <= 3) {
            adapterways[i].first += adapterways[i-3].first;
        }
    }

    part2 = adapterways.back().first;

    std::cout << "The result to part 1 is: " << part1 << "!\n";
    std::cout << "The result to part 2 is: " << part2 << "!\n";

}
