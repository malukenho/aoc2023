#include <algorithm>
#include <numeric>
#include <vector>

#ifndef UTILS_INCLUDED
#include "utils.cpp"
#endif

using namespace std;

using int64 = long long;

/**
 * Advent of Code 2023, Day 9 - Mirage Maintenance
 *
 * Problem Description: http://adventofcode.com/2023/day/9
 * Blog Posts: https://malukenho.github.io/post/2023/12/01/advent-of-code-2023.html
 */
class Solution_09 {
public:
    static int64 part1(const vector<vector<int64>> &lines) {
        int64 sum = 0;

        for (vector<int64> data: lines) {
            do {
                if (data.empty())
                    continue;
                sum += data.back();
                std::adjacent_difference(data.begin(), data.end(), data.begin());
                data.erase(data.begin());
            } while (!std::all_of(data.begin(), data.end(),
                                  [](auto d) { return d == 0; }));
        }

        return sum;
    }

    static int64 part2(const vector<vector<int64>> &lines) {
        int64 sum = 0;

        for (vector<int64> data: lines) {
            vector<int64> ans;
            do {
                if (data.empty())
                    continue;
                ans.push_back(data.front());
                std::adjacent_difference(data.begin(), data.end(), data.begin());
                data.erase(data.begin());
            } while (!ranges::all_of(data,
                                     [](auto d) { return d == 0; }));
            int64 first{};
            for (size_t i = ans.size(); i > 0; --i) {
                first = ans[i - 1] - first;
            }
            sum += first;
        }

        return sum;
    }
};
