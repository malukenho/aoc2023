#include <string>
#include <numeric>
#include <unordered_map>
#include <set>
#include <tuple>

#include "src/Solution_01.cpp"
#include "src/Solution_02.cpp"
#include "src/Solution_03.cpp"
#include "src/Solution_04.cpp"
#include "src/Solution_05.cpp"
#include "src/Solution_06.cpp"
#include "src/Solution_07.cpp"
#include "src/Solution_08.cpp"
#include "src/Solution_09.cpp"
#include "src/Solution_10.cpp"
#include "src/Solution_11.cpp"

using namespace std;

int main() {
    std::cout << "Day #1\n";
    string day_01_input = Utils::read_file("../input/day_01_input");
    Utils::invariant(55816, Solution_01::part1(day_01_input));
    Utils::invariant(55816, Solution_01::part1TwoPointer(day_01_input));
    Utils::invariant(54980, Solution_01::part2(day_01_input));

     std::cout << "\nDay #2\n";
     string day_02_input = Utils::read_file("../input/day_02_input");
     Utils::invariant(2348, Solution_02::part1(day_02_input));
     Utils::invariant(76008, Solution_02::part2(day_02_input));

     std::cout << "\nDay #3\n";
     std::vector<std::string> day_03_input =
             Utils::split_lines(Utils::read_file("../input/day_03_input"));
     Utils::invariant(550934, Solution_03::part1(day_03_input));
     Utils::invariant(81997870, Solution_03::part2(day_03_input));

     std::cout << "\nDay #4\n";
     std::vector<std::string> day_04_input =
             Utils::split_lines(Utils::read_file("../input/day_04_input"));
     Utils::invariant(32001ll, (long long) Solution_04::part1(day_04_input));
     Utils::invariant(5037841, Solution_04::part2(day_04_input));

     std::cout << "\nDay #5\n";
     std::vector<std::string> day_05_input =
     Utils::split_lines(Utils::read_file("../input/day_05_input"));
//     Utils::invariant(806029445ll, Solution_05::part1(day_05_input));
//     Utils::invariant(59370572ll, Solution_05::part2(day_05_input));
//     Utils::invariant(46ll, Solution_05::solve());
//
     std::cout << "\nDay #6\n";
     std::vector<std::string> day_06_input =
             Utils::split_lines(Utils::read_file("../input/day_06_input"));
     Utils::invariant(316800ll, Solution_06::part1());
     Utils::invariant(45647654ll, Solution_06::part2());

     std::cout << "\nDay #7\n";
     std::vector<std::string> day_07_input =
     Utils::split_lines(Utils::read_file("../input/day_07_input"));
//     Utils::invariant(316800ll, Solution_07::part1(day_07_input));
//     Utils::invariant(45647654ll, Solution_06::part2());

     std::cout << "\nDay #8\n";
     Solution_08 day_08 =
             Solution_08(Utils::split_lines(Utils::read_file("../input/day_08_input")));
     Utils::invariant(20777ll, day_08.part1());
     Utils::invariant(13289612809129ll, day_08.part2());

     std::cout << "\nDay #9\n";
     std::vector<std::string> input =
             Utils::split_lines(Utils::read_file("../input/day_09_input"));

//     vector<vector<int64> > day_09_input(input.size(), vector<int64>());

//     for (auto &n: input) {
//         day_09_input.push_back(Utils::parse_v_numbers(n));
//     }

//     Utils::invariant(20777ll, Solution_09::part1(day_09_input));
//     Utils::invariant(13289612809129ll, Solution_09::part2(day_09_input));
//     std::cout << Solution_10::part1() << std::endl;

    std::cout << "\nDay #11\n";
    std::vector<std::string> day_11_input =
            Utils::split_lines(Utils::read_file("../input/day_11_input"));

     Utils::invariant(9565386ll, Solution_11::part1(day_11_input));


    return 0;
}
