#include <set>
#include <string>
#include <vector>

using namespace std;

using int64 = long long;

/**
 * Advent of Code 2023, Day 6 - Wait For It
 *
 * Problem Description: http://adventofcode.com/2023/day/6
 * Blog Posts: https://malukenho.github.io/post/2023/12/01/advent-of-code-2023.html
 */
class Solution_06 {
private:
public:
    static int64 part1() {
        return solve({61, 67, 75, 71}, {430, 1036, 1307, 1150});
    }

    static int64 part2() {
        return solve({61677571ll}, {430103613071150ll});
    }

    static int64 solve(const vector<int64> &times, const vector<int64> &distance) {
        vector<int64> A;
        for (int i = 0; i < times.size(); ++i) {
            int64 ans = 0;
            int64 n = 1;
            while (n < times[i]) {
                if ((n * (times[i] - n)) > distance[i]) {
                    ans++;
                }
                n++;
            }
            A.push_back(ans);
        }

        int64 ans = 1;
        for (const int64 &i: A) {
            ans *= i;
        }

        return ans;
    }
};
