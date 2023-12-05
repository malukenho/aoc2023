#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

using int64 = long long;

const int INF = INT_MAX;

/**
 * Advent of Code 2023, Day 5 - If You Give A Seed A Fertilizer
 *
 * Problem Description: http://adventofcode.com/2023/day/5
 * Blog Posts: https://malukenho.github.io/post/2023/12/01/advent-of-code-2023.html
 */
class Solution_05 {
private:
    constexpr static array<string_view, 7> keys = {
            "soil",
            "fertilizer",
            "water",
            "light",
            "temperature",
            "humidity",
            "location"
    };

public:
    static int64 part1(vector<string> &almanac) {
        vector<int64> seeds = Utils::parse_v_numbers(almanac[0].substr(almanac[0].find(':') + 2));

        // TODO: remove this pointer
        int keyPointer = -1;

        // TODO: Do I need this map?
        vector<string> keys = {
                "soil",
                "fertilizer",
                "water",
                "light",
                "temperature",
                "humidity",
                "location"
        };

        unordered_map<string, vector<tuple<int64, int64, int64>>> M;

        for (int i = 2; i < almanac.size(); ++i) {
            if (almanac[i].empty()) continue;

            if (almanac[i].find('-') != string::npos) {
                keyPointer++;
                continue;
            }

            string key = keys[keyPointer];
            vector<int64> R = Utils::parse_v_numbers(almanac[i]);

            if (M.find(key) == M.end()) {
                M[key] = vector<tuple<int64, int64, int64>>();
            }

            M[key].push_back(std::make_tuple(R[0], R[1], R[2]));
        }

        for (int i = 0; i < seeds.size(); ++i) {
            int64 &seed = seeds[i];

            for (int key = 0; key < keys.size(); key++) {
                for (auto &m: M[keys[key]]) {
                    int64 destination_range = get<0>(m);
                    int64 source_range = get<1>(m);
                    int64 range_length = get<2>(m);

                    if (seed >= source_range && seed < source_range + range_length) {
                        seed += destination_range - source_range;
                        break;
                    }
                }
            }
        }

        sort(seeds.begin(), seeds.end());

        return seeds[0];
    }

    static int64 part2(const vector<string> &almanac) {
        vector<int64> input = Utils::parse_v_numbers(almanac[0].substr(almanac[0].find(':') + 2));
        // TODO: Do I need this map?
        vector<string> keys = {
                "soil",
                "fertilizer",
                "water",
                "light",
                "temperature",
                "humidity",
                "location"
        };

        unordered_map<string, vector<tuple<int64, int64, int64>>> M;

        // TODO: remove this pointer
        int keyPointer = -1;
        for (int i = 2; i < almanac.size(); ++i) {
            if (almanac[i].empty()) continue;

            if (almanac[i].find('-') != string::npos) {
                keyPointer++;
                continue;
            }

            string key = keys[keyPointer];
            vector<int64> R = Utils::parse_v_numbers(almanac[i]);

            if (M.find(key) == M.end()) {
                M[key] = vector<tuple<int64, int64, int64>>();
            }

            M[key].push_back(std::make_tuple(R[0], R[1], R[2]));
        }


        vector<tuple<int64, int64>> seeds;

        // TODO: remove this
        for (int i = 0; i < input.size(); i += 2) {
            seeds.push_back({input[i], input[i] + input[i + 1] - 1});
        }

        vector<tuple<int64, int64>> ranges;
        while (!seeds.empty()) {
            tuple<int64, int64> seed = seeds.back();
            seeds.pop_back();
            int64 s, e;
            tie(s, e) = seed;

            bool appended = false;
            for (auto &m: M) {
                for (auto &t: m.second) {
                    int64 a, b, c;
                    tie(a, b, c) = t;

                    int64 os = max(s, b);
                    int64 oe = min(e, b + c);
                    if (os < oe) {
                        ranges.push_back({os - b + a, oe - b + a});
                        if (os > s) seeds.push_back({s, os - 1});
                        if (e > oe) seeds.push_back({oe + 1, e});
                        appended = true;
                        break;
                    }
                }
            }

            if (!appended) ranges.push_back(seed);
        }

        int64 ans2 = LONG_LONG_MAX;
        for (auto s: ranges) ans2 = min(ans2, get<0>(s));

        return ans2;
    }
};
