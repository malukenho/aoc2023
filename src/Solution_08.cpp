#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

#ifndef UTILS_INCLUDED
#include "utils.cpp"
#endif

using namespace std;

using int64 = long long;

/**
 * Advent of Code 2023, Day 8 - Haunted Wasteland
 *
 * Problem Description: http://adventofcode.com/2023/day/8
 * Blog Posts: https://malukenho.github.io/post/2023/12/01/advent-of-code-2023.html
 */
class Solution_08 {
private:
    string instructions;
    vector<string> starting_points;
    map<string, pair<string, string>> M;

public:
    Solution_08(const vector<string> &lines) {
        instructions = lines[0];

        for (int i = 2; i < lines.size(); ++i) {
            string key = lines[i].substr(0, 3);

            if (key[2] == 'Z') starting_points.push_back(key);
            M[key] = {lines[i].substr(7, 3), lines[i].substr(12, 3)};
        }
    }

    int64 part1() { return cycle({"AAA"}); }

    int64 part2() { return cycle(starting_points); }

    int64 cycle(const vector<string>& points) {
        int64 steps = 0;

        vector<int64> step_counts;
        for (const auto &k: points) {
            string current = k;
            while (true) {
                for (const char &c: instructions) {
                    if (c == 'R') current = M[current].second;
                    else current = M[current].first;
                    steps++;
                }

                if (current.ends_with('Z')) {
                    step_counts.push_back(steps);
                    steps = 0;
                    break;
                }
            }
        }

        int64 lcm = step_counts[0];
        for (int i = 1; i < step_counts.size(); ++i) {
            lcm = lcm * step_counts[i] / gcd(lcm, step_counts[i]);
        }

        return lcm;
    }
};

