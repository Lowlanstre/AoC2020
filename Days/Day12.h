#pragma once

#include <fstream>
#include <iostream>
#include <vector>

class Day12 {

public:
    static void solve();
private:
    static void move(std::pair<int,int>& loc, int com, int mult);
    static void rotate(std::pair<int,int>& way,char com,int mult);
};