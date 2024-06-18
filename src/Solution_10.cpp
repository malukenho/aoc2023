//#include <algorithm>
//#include <queue>
//#include <unordered_map>
//#include <vector>

using namespace std;

using int64 = long long;

/**
 * Advent of Code 2023, Day 10 - Pipe Maze
 *
 * Problem Description: http://adventofcode.com/2023/day/10
 * Blog Posts: https://malukenho.github.io/post/2023/12/01/advent-of-code-2023.html
 */
class Solution_10 {
public:
    static int64 part1() {
        /*

          | is a vertical pipe connecting north and south.

          - is a horizontal pipe connecting east and west.

          L is a 90-degree bend connecting north and east.

          J is a 90-degree bend connecting north and west.

          7 is a 90-degree bend connecting south and west.

          F is a 90-degree bend connecting south and east.

          . is ground; there is no pipe in this tile.

          S is the starting position of the animal; there is a
            pipe on this tile, but your sketch doesn't show what
            shape the pipe has.

        */
//        const vector<vector<char>> mm = {
//            {'.', '.', 'F', '7', '.'},
//            {'.', 'F', 'J', '|', '.'},
//            {'S', 'J', '.', 'L', '7'},
//            {'|', 'F', '-', '-', 'J'},
//            {'L', 'J', '.', '.', '.'},
//        };
//
//        const vector<vector<int>> D = {
//            {-1, 0},
//            {0, -1},
//            {1, 0},
//            {0, 1},
//        };
//
//        unordered_map<pair<int, int>, bool> M;
//        queue<pair<int, int>> Q;
//
//        for (int i = 0; i < mm.size(); ++i) {
//            for (int j = 0; j < mm[0].size(); ++j) {
//                if (M.contains({i, j})) {
//                    continue;
//                }
//
//                M[{i, j}] = true;
//
//                if (mm[i][j] == '.') continue;
//
//                for (auto n: D) {
//                    if (i+n[0] >= 0 && j+n[1] >=0 && i+n[0] < mm.size() && j+n[1] < mm[0].size()) {
//                        Q.emplace(i+n[0], j+n[1]);
//                    }
//                }
//            }
//        }
//
        return 1;
    }
};