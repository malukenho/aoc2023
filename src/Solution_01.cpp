#include <string>
#include <unordered_map>

using namespace std;

/**
 * Advent of Code 2023, Day 1 - Trebuchet?!
 *
 * Problem Description: http://adventofcode.com/2023/day/1
 * Blog Posts: https://malukenho.github.io/post/2023/12/01/advent-of-code-2023.html
 */
class Solution_01 {
public:
    static int part1(string &calibration_values) {
        int sum = 0;
        char first_digit = ' ';
        char last_digit = ' ';

        for (char &current_char: calibration_values) {
            if (current_char == '\n') {
                if (first_digit != ' ' && last_digit != ' ') {
                    sum += (first_digit - '0') * 10 + (last_digit - '0');
                }
                first_digit = ' ';
                last_digit = ' ';
                continue;
            }

            if (current_char >= '0' && current_char <= '9') {
                if (first_digit == ' ') first_digit = current_char;
                last_digit = current_char;
            };
        }

        if (first_digit != ' ' && last_digit != ' ')
            sum += (first_digit - '0') * 10 + (last_digit - '0');

        return sum;
    }

    static int part1TwoPointer(string &input) {
        int ans = 0;
        char right = ' ';
        char left = ' ';

        int rp = 0;
        int lp = input.size() - 1;

        while (rp < input.size() && lp > 0) {
            if (input[rp] == '\n') {
                if (right != ' ') ans += (right - '0') * 10;
                right = ' ';
            }

            if (input[lp] == '\n') {
                if (left != ' ') ans += left - '0';
                left = ' ';
            }

            if (input[rp] >= '0' && input[rp] <= '9') {
                if (right == ' ') right = input[rp];
            };

            if (input[lp] >= '0' && input[lp] <= '9') {
                if (left == ' ') left = input[lp];
            };

            rp++;
            lp--;
        }

        if (right != ' ') ans += (right - '0') * 10;
        if (left != ' ') ans += left - '0';

        return ans;
    }

    static int part2(string &input) {
        unordered_map<string, string> C = {
                {"one",   "o1e"},
                {"two",   "t2o"},
                {"three", "t3e"},
                {"four",  "f4r"},
                {"five",  "f5e"},
                {"six",   "s6x"},
                {"seven", "s7n"},
                {"eight", "e8t"},
                {"nine",  "n9e"},
        };

        for (auto &i: C) {
            unsigned long pos = input.find(i.first);
            while (pos != string::npos) {
                input.replace(pos, i.first.size(), i.second);
                pos = input.find(i.first);
            }
        }

        return part1(input);
    }
};
