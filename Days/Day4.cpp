#include "Day4.h"

void Day4::solve() {

    int part1 = 0;
    int part2 = 0;

    std::ifstream inputstream;
    std::stringstream sstream;
    inputstream.open("..\\Input\\day4.txt");

    sstream << inputstream.rdbuf();

    bool missing = false;
    bool invalid = false;
    std::string passport;
    std::vector<std::string>fields;
    std::vector<std::regex>regFields;



    fields.emplace_back("byr");
    fields.emplace_back("iyr");
    fields.emplace_back("eyr");
    fields.emplace_back("hgt");
    fields.emplace_back("hcl");
    fields.emplace_back("ecl");
    fields.emplace_back("pid");

    std::regex byr ("byr:([1][9][2-9][0-9])|([2][0][0][0-2])\\s");
    std::regex iyr ("iyr:([2][0][1][0-9])|([2][0][2][0])\\s");
    std::regex eyr ("eyr:([2][0][2][0-9])|([2][0][3][0])\\s");
    std::regex hgt ("hgt:((\\b([5][9]|[6][0-9]|[7][0-6])in)|(\\b([1][5-8][0-9]|[1][9][0-3])cm))\\s");
    std::regex hcl ("hcl:#([0-9]|[a-f]){6}\\s");
    std::regex ecl ("ecl:((amb)|(blu)|(brn)|(gry)|(grn)|(hzl)|(oth))");
    std::regex pid ("pid:\\d{9}\\s");

    regFields.emplace_back(byr);
    regFields.emplace_back(iyr);
    regFields.emplace_back(eyr);
    regFields.emplace_back(hgt);
    regFields.emplace_back(hcl);
    regFields.emplace_back(ecl);
    regFields.emplace_back(pid);

    std::smatch matches;

    while(!sstream.eof()) {

        std::string passline;

        std::getline(sstream, passline);

        if (passline.empty()) {

            passport += " ";

            for (const auto &f : fields) {
                if (passport.find(f) == std::string::npos)
                    missing = true;
            }

        if (missing) {
            missing = false;
        }
        else {
            ++part1;

            for(const auto &r : regFields) {

                std::regex_search(passport,matches,r);

                if(matches.empty())
                    invalid = true;
            }

            if(invalid)
                invalid = false;
            else
                ++part2;
        }

        passport.clear();

    } else {
            passport += " " + passline;
        }
    }

    std::cout << "The result to part 1 is: " << part1 << "!\n";
    std::cout << "The result to part 2 is: " << part2 << "!\n";

}
