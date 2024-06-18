#include <string>
#include <numeric>
#include <unordered_map>
#include <set>
#include <tuple>

#ifndef UTILS_INCLUDED
#include "utils.cpp"
#endif


using namespace std;

/**
 * Advent of Code 2023, Day 3 - Gear Ratios
 *
 * Problem Description: http://adventofcode.com/2023/day/3
 * Blog Posts: https://malukenho.github.io/post/2023/12/01/advent-of-code-2023.html
 */
class Solution_03 {
private:
    static constexpr int P[8][2] = {{0,  1},
                                    {1,  0},
                                    {0,  -1},
                                    {-1, 0},
                                    {1,  1},
                                    {-1, -1},
                                    {-1, 1},
                                    {1,  -1}};

public:
    static int part1(vector<string> &engine_schematic) {
        vector<long long> ans;

        for (auto &L: engine_schematic) L = "." + L + ".";

        for (int i = 0; i < engine_schematic.size(); ++i) {
            string number;
            bool valid = false;

            string line = engine_schematic[i];

            for (int j = 0; j < line.size(); ++j) {
                if (Utils::is_digit(line[j])) {
                    number += line[j];

                    for (auto &k: P) {
                        int x = i + k[0];
                        int y = j + k[1];

                        if (x < 0 || x >= engine_schematic.size()) continue;
                        if (y < 0 || y >= line.size()) continue;

                        if (!Utils::is_digit(engine_schematic[x][y])) {
                            if (engine_schematic[x][y] != '.') valid = true;

                            continue;
                        }

                    }
                    continue;
                }

                if (!number.empty() && valid) ans.push_back(stol(number));
                number = "";
                valid = false;
            }
        }

        return accumulate(ans.begin(), ans.end(), 0);
    }

    static int part2(vector<string> &engine_schematic) {
        vector<long long> ans;

        for (auto &L: engine_schematic) L = "." + L + ".";

        for (int i = 0; i < engine_schematic.size(); ++i) {
            string number;
            string line = engine_schematic[i];

            for (int j = 0; j < line.size(); ++j) {
                if (line[j] == '*') {
                    set<tuple<int, int, int>> seen;

                    for (auto &k: P) {
                        int x = i + k[0];
                        int y = j + k[1];

                        if (x < 0 || x >= engine_schematic.size()) continue;
                        if (y < 0 || y >= line.size()) continue;

                        if (Utils::is_digit(engine_schematic[x][y])) {
                            tuple<int, int, int> r = expand_bounds(engine_schematic, x, y);
                            seen.insert(r);
                        }
                    }

                    if (seen.size() > 1) {
                        int sum = 1;
                        for (auto &r: seen) {
                            sum *= get<2>(r);
                        }

                        ans.push_back(sum);
                    }
                    seen.clear();
                }
            }
        }

        return accumulate(ans.begin(), ans.end(), 0);
    }

    static tuple<int, int, int> expand_bounds(vector<string> &engine_schematic, int x, int y) {
        string ans;
        ans += engine_schematic[x][y];

        int init = y;
        int end = y;

        int i = -1;
        while (Utils::is_digit(engine_schematic[x][y + i]) && y + i >= 0) {
            init = y + i;
            ans = engine_schematic[x][y + i] + ans;
            i--;
        }

        int k = 1;
        while (Utils::is_digit(engine_schematic[x][y + k]) && y + k < engine_schematic[x].size()) {
            end = y + k;
            ans += engine_schematic[x][y + k];
            k++;
        }

        return {init, end, stoi(ans)};
    }
};
