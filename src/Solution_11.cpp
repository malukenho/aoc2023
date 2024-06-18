#include "vector"

#ifndef UTILS_INCLUDED
#include "utils.cpp"
#endif

using namespace std;

using int64 = long long;

struct Galaxy {
    int row;
    int col;
};

/**
 * Advent of Code 2023, Day 11 - Cosmic Expansion
 *
 * Problem Description: http://adventofcode.com/2023/day/11
 * Blog Posts: https://malukenho.github.io/post/2023/12/11/advent-of-code-2023.html
 */
class Solution_11 {
public:
    static int64 solve(vector<string> grid, int times) {
        vector<bool> rowIsEmpty(grid.size(), true);
        vector<bool> colIsEmpty(grid[0].size(), true);

        vector<Galaxy> galaxies;

        for (int64 i = 0; i < grid.size(); i++) {
            for (int64 j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '#') {
                    rowIsEmpty[i] = false;
                    colIsEmpty[j] = false;

                    Galaxy galaxy = {static_cast<int>(i), static_cast<int>(j)};
                    galaxies.push_back(galaxy);
                }
            }
        }

        int64 ans = 0;
        for (int64 aIdx = 0; aIdx < galaxies.size(); aIdx++) {
            for (int64 bIdx = aIdx + 1; bIdx < galaxies.size(); bIdx++) {
                const auto& ga = galaxies[aIdx];
                const auto& gb = galaxies[bIdx];

                int dist = getDist(ga, gb, rowIsEmpty, colIsEmpty, times);

                ans += dist;
            }
        }

        return ans;
    }

private:
    static int getDist(
            const Galaxy &ga,
            const Galaxy &gb,
            const vector<bool> &rowIsEmpty,
            const vector<bool> &colIsEmpty,
            const int times
    ) {
        int dr = abs(ga.row - gb.row);
        int dc = abs(ga.col - gb.col);

        int dist = dr + dc;
        for (int i = min(ga.row, gb.row) + 1; i < max(gb.row, gb.row); i++) {
            dist += times * rowIsEmpty[i];
        }
        for (int j = min(ga.col, gb.col) + 1; j < max(ga.col, gb.col); j++) {
            dist += times * colIsEmpty[j];
        }
        return dist;
    }
};