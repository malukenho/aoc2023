#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

/**
 * Advent of Code 2023, Day 2 - Cube Conundrum
 *
 * Problem Description: http://adventofcode.com/2023/day/2
 * Blog Posts: https://malukenho.github.io/post/2023/12/01/advent-of-code-2023.html
 */
class Solution_02 {
public:
    static int part1(string &game_records) {
        return calculate(
            game_records,
            [=](vector<int> &possible_rounds, unordered_map<string, int> &round_map, int index) -> bool {
                possible_rounds.push_back(index + 1);
                round_map.clear();

                return true;
            },
            [=](unordered_map<string, int> round_map) -> bool {
                return round_map["red"] <= 12 && round_map["green"] <= 13 && round_map["blue"] <= 14;
            }
        );
    }

    static int part2(string &game_records) {
        return calculate(
                game_records,
                [=](vector<int> &possible_rounds, unordered_map<string, int> &round_map, int index) -> bool {
                    possible_rounds.push_back(round_map["red"] * round_map["green"] * round_map["blue"]);
                    round_map.clear();

                    return true;
                },
                [=](const unordered_map<string, int>& round_map) -> bool { return true; }
        );
    }

private:
    static int calculate(
        string &game_records,
        const function<void(vector<int>&, unordered_map<string, int>&, int)> aggregate,
        const function<bool(unordered_map<string, int>)> predicate
    ) {
        vector<string> rounds = Utils::split_lines(game_records);
        vector<int> possible_rounds;

        string cube_color;
        string cube_quantity;
        for (int i = 0; i < rounds.size(); ++i) {
            unordered_map<string, int> round_map;
            string round = rounds[i];

            round = round.substr(round.find(':') + 2) + ";";

            cube_quantity = "";
            cube_color = "";
            for (char &current_char: round) {
                if (current_char == ',' || current_char == ';') {
                    round_map[cube_color]  = max(round_map[cube_color], stoi(cube_quantity));
                    cube_color = "";
                    cube_quantity = "";
                    continue;
                }

                if (current_char == ' ') continue;

                if (current_char >= '0' && current_char <= '9') cube_quantity += current_char;
                else cube_color += current_char;
            }

            if (predicate(round_map)) aggregate(possible_rounds, round_map, i);
        }

        return accumulate(possible_rounds.begin(), possible_rounds.end(), 0);
    }
};
