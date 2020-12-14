#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>

class Day7 {

public:
    static void solve();

private:
    static long long inside(std::string& name,std::vector<std::pair<std::string,std::vector<std::pair<int,std::string>>>>& bags);
};