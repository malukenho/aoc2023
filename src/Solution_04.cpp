#include <string>
#include <numeric>
#include <unordered_map>
#include <set>
#include <map>

#ifndef UTILS_INCLUDED
#include "utils.cpp"
#endif

using namespace std;

/**
 * Advent of Code 2023, Day 4 - Scratchcards
 *
 * Problem Description: http://adventofcode.com/2023/day/4
 * Blog Posts: https://malukenho.github.io/post/2023/12/01/advent-of-code-2023.html
 */
class Solution_04 {
public:
    static int part1(vector<string> &scratchcards) {
        vector<int> ans;

        for (string &scratchcard: scratchcards) {
            set<int> intersect = intersection(scratchcard);

            unsigned long size = intersect.size();

            if (size <= 0) continue;
            int calc = 1;
            while (--size) { calc *= 2; }
            ans.push_back(calc);
        }

        return accumulate(ans.begin(), ans.end(), 0);
    }

    static int part2(vector<string> &scratchcards) {
        vector<int> ans;
        map<int, int> M;

        M[0] = 0;
        for (int i = 0; i < scratchcards.size(); ++i) {
            set<int> intersect = intersection(scratchcards[i]);

            for (auto j = 0; j < intersect.size(); ++j) {
                M[i + j + 1] += M[i] + 1;
            }

            ans.push_back(M[i] + 1);
        }

        return accumulate(ans.begin(), ans.end(), 0);
    }

private:
    static set<int> intersection(const string &scratchcard) {
        string winning_numbers = scratchcard.substr(scratchcard.find(':') + 2,
                                                    scratchcard.find('|') - 2 - scratchcard.find(':'));

        string scratchcard_numbers = scratchcard.substr(scratchcard.find('|') + 1);

        set<int> S = Utils::parse_numbers(winning_numbers);
        set<int> T = Utils::parse_numbers(scratchcard_numbers);

        set<int> intersect;
        set_intersection(S.begin(), S.end(), T.begin(), T.end(),
                         inserter(intersect, intersect.begin()));

        return intersect;
    }
};
