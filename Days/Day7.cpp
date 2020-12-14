#include "Day7.h"


void Day7::solve() {

    int part1 = 0;
    long long part2 = 0;

    std::ifstream inputstream;
    std::stringstream sstream;
    inputstream.open("..\\Input\\day7.txt");

    std::vector<std::pair<std::string,std::vector<std::pair<int,std::string>>>>bags;
    std::vector<std::pair<int,std::string>>insides;

    int last;
    std::set<std::string>shinygold;
    shinygold.emplace("shinygold");

    int count;
    std::string inside;
    std::string bag;
    std::string first;
    std::string second;
    std::string garbage;

    while(!inputstream.eof()) {

        std::string line;

        std::getline(inputstream,line);

        sstream << line;
        sstream >> first >> second >> garbage >> garbage;
        bag = first + second;

        while(!sstream.eof()) {
            sstream >> garbage >> first >> second;
            if(garbage == "no") {
                break;
            }
            count = std::stoi(garbage);
            sstream >> garbage;
            insides.emplace_back(count,first+second);
        }
        bags.emplace_back(bag,insides);
        insides.clear();
        sstream.clear();
    }

    while(true) {

        last = shinygold.size();

        bool contains = false;

        for(auto &b : bags) {
            for(auto &p : b.second) {
                for(auto &sb : shinygold) {
                    if (p.second == sb) {
                        contains = true;
                        break;
                    }
                }
            }
            if(contains) {
                    shinygold.emplace(b.first);
                    contains = false;
            }
        }
        if(last == shinygold.size()) {
            part1 = last-1;
            break;
        }
    }

    std::string sg = "shinygold";
    part2 = Day7::inside(sg,bags)-1;

    std::cout << "The result to part 1 is: " << part1 << "!\n";
    std::cout << "The result to part 2 is: " << part2 << "!\n";

}

long long Day7::inside(std::string& name, std::vector<std::pair<std::string, std::vector<std::pair<int, std::string>>>>& bags) {

    for(auto &b : bags) {

        if(b.first == name) {

            if(b.second.empty()) {
                return 1;
            } else {
                long long total = 1;
                for(auto &c : b.second) {
                    total += c.first*inside(c.second,bags);
                }
                return total;
            }
        }
    }
}
