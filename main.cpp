#include <string>

#include "src/utils.cpp"
#include "src/Solution_01.cpp"
#include "src/Solution_02.cpp"
#include "src/Solution_03.cpp"
#include "src/Solution_04.cpp"

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
    std::vector<std::string> day_03_input = Utils::split_lines(Utils::read_file("../input/day_03_input"));
    Utils::invariant(550934, Solution_03::part1(day_03_input));
    Utils::invariant(81997870, Solution_03::part2(day_03_input));

    std::cout << "\nDay #4\n";
    std::vector<std::string> day_04_input = Utils::split_lines(Utils::read_file("../input/day_04_input"));
    Utils::invariant(32001ll, Solution_04::part1(day_04_input));
    Utils::invariant(5037841, Solution_04::part2(day_04_input));

    return 0;
}
