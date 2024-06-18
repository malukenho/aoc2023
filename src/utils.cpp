#include <iostream>
#include <string>
#include <fstream>
#include <set>

#define UTILS_INCLUDED 1

class Utils {
public:
    // TODO: Make it a template
    static void invariant(int expected, int actual) {
        if (expected != actual) {
            std::cout << "Expected: " << expected << " Actual: " << actual << std::endl;
            exit(1);
        }

        std::cout << "✨ Passed" << std::endl;
    }

    static std::string read_file(const std::string &file_path) {
        std::string line;
        std::fstream file(file_path);

        std::string input;
        while (getline(file, line)) {
            input += line + "\n";
        }

        return input;
    }

    static std::vector<std::string> split_lines(const std::string &file_content) {
        std::vector<std::string> lines;
        std::string line;

        for (char current_char: file_content) {
            if (current_char == '\n') {
                lines.push_back(line);
                line = "";
            } else {
                line += current_char;
            }
        }

        return lines;
    }

    static std::set<int> parse_numbers(std::string text) {
        std::set<int> S;

        text += ' ';
        std::string n;
        for (char &c: text) {
            if (c == ' ') {
                if (!n.empty()) S.insert(stoi(n));
                n = "";
                continue;
            }
            n += c;
        }
        return S;
    }

    static bool is_digit(char c) {
        return c >= '0' && c <= '9';
    }

    static std::vector<long long> parse_v_numbers(std::string text) {
        std::vector<long long> S;

        text += ' ';
        std::string n;
        for (char &c: text) {
            if (c == ' ') {
                if (!n.empty()) S.push_back(stoll(n));
                n = "";
                continue;
            }
            n += c;
        }
        return S;
    }
};