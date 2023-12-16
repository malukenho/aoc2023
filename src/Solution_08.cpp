#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

using int64 = long long;

/**
 * Advent of Code 2023, Day 8 - Haunted Wasteland
 *
 * Problem Description: http://adventofcode.com/2023/day/8
 * Blog Posts: https://malukenho.github.io/post/2023/12/01/advent-of-code-2023.html
 */
class Solution_08 {
public:
    static int64 part1(const vector<string> &lines) {
        string instructions = lines[0];

        map<string, pair<string, string>> M;

        int num_of_paths = 0;
        for (int i = 2; i < lines.size(); ++i) {
            string key = lines[i].substr(0, 3);

            if (key[2] == 'A') num_of_paths++;
            M[key] = {lines[i].substr(7, 3), lines[i].substr(12, 3)};
        }

        int64 ans = 0;

        const string NEEDLE = "ZZZ";
        string haystack = "AAA";

        while (haystack != NEEDLE) {
            for (const char &c: instructions) {
                if (c == 'R') haystack = M[haystack].second;
                else haystack = M[haystack].first;
                ans++;
            }

            if (haystack == NEEDLE) {
                break;
            }
        }

        return ans;
    }

    static int64 part2(const vector<string> &lines) {
        string instructions = lines[0];

        map<string, pair<string, string>> M;

        vector<string> ans;
        for (int i = 2; i < lines.size(); ++i) {
            string key = lines[i].substr(0, 3);

            if (key[2] == 'A') ans.push_back(key);
            M[key] = {lines[i].substr(7, 3), lines[i].substr(12, 3)};
        }

        int64 steps = 0;

        vector<int64> step_counts;

        for (const auto &k: ans) {
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

