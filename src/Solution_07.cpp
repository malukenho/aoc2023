#include <set>
#include <string>
#include <vector>
#include <map>

#ifndef UTILS_INCLUDED
#include "utils.cpp"
#endif

using namespace std;

using int64 = long long;

struct Hand {

  enum HANDS {
    FIVE_OF_A_KIND,
    FOUR_OF_A_KIND,
    FULL_HOUSE,
    THREE_OF_A_KIND,
    TWO_PAIR,
    ONE_PAIR,
    HIGH_CARD
  };

  string hand;
  int order;
  int bid;

  // TODO: move parsing of the line here
  // TODO: also calculate the type here already??
  Hand(string _hand, int _bid) {
    hand = _hand;
    bid = _bid;
  }

  int orderOfImportance() { return bid; }
};

/**
 * Advent of Code 2023, Day 7 - Camel Cards
 *
 * Problem Description: http://adventofcode.com/2023/day/7
 * Blog Posts:
 * https://malukenho.github.io/post/2023/12/01/advent-of-code-2023.html
 */
class Solution_07 {
public:
  static int64 part1(const vector<string> &hands) {

    // A, K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, or 2
    //      - [x]  Five of a kind, where all five cards have the same label:
    //      AAAAA
    //      - [x]  Four of a kind, where four cards have the same label and one
    //      card has a different label: AA8AA
    //      - [x]  Full house, where three cards have the same label, and the
    //      remaining two cards share a different label: 23332
    //      - [x]  Three of a kind, where three cards have the same label, and
    //      the remaining two cards are each different from any other card in
    //      the hand: TTT98
    //      - [x]  Two pair, where two cards share one label, two other cards
    //      share a second label, and the remaining card has a third label:
    //      23432
    //      - [x]  One pair, where two cards share one label, and the other
    //      three cards have a different label from the pair and each other:
    //      A23A4
    //      - [x]  High card, where all cards' labels are distinct: 23456

    vector<Hand> M;
    for (const string &hand : hands) {
      M.push_back(Hand(hand, 1));
    }

    // How to do a sorting?
    return 123;

    // TODO: I think I can create a map of maps
    // where the key is the hand and the value is the map of cards
    // after that I can iterate over the map of maps and apply the second
    // ordering
    //
    //        map<HANDS, vector<string>> MAPS;
    //
    //        // debug M
    //        for (const auto &m: M) {
    //            // Easy to solve
    //            if (m.size() == 1) {
    //                MAPS[FIVE_OF_A_KIND].push_back(m.begin()->first);
    //                cout << "Five of a kind" << endl;
    //            }
    //            // Easy to solve
    //            if (m.size() == 5) {
    //                MAPS[HIGH_CARD].push_back(m.begin()->first);
    //                cout << "High card a kind" << endl;
    //            }
    //
    //            bool is_pair = false;
    //            bool is_double_pair = false;
    //
    //            bool is_three = false;
    //
    //            for (const auto &p: m) {
    //                if (p.second == 4) {
    //                    MAPS[FOUR_OF_A_KIND].push_back(p.first);
    //                    cout << "Four of a kind" << endl;
    //                    break;
    //                }
    //                if (p.second == 3) is_three = true;
    //                if (p.second == 2) {
    //                    if (!is_pair) is_pair = true;
    //                    else is_double_pair = true;
    //
    //                    if (is_double_pair) {
    //                        MAPS[TWO_PAIR].push_back(p.first);
    //                        cout << "Double pair" << endl;
    //                    } else {
    //                        MAPS[ONE_PAIR].push_back(p.first);
    //                        cout << "Pair" << endl;
    //                    }
    ////                    cout << (!is_double_pair ? "Pair" : "Double Pair")
    ///<< endl;
    //                }
    ////                cout << p.first << " " << p.second << endl;
    //            }
    //            if (is_three) {
    //                if (is_pair) {
    //                    MAPS[FULL_HOUSE].push_back(m.begin()->first);
    //                    cout << "Full house" << endl;
    //                } else {
    //                    MAPS[THREE_OF_A_KIND].push_back(m.begin()->first);
    //                    cout << "Three of a kind" << endl;
    //                }
    //            }
    //            cout << endl;
    //        }
    //
    //        vector<int64> ans;
    //
    //        // Debug MAPS
    //        for (const auto &m: MAPS) {
    //            cout << m.first << ":" << endl;
    //            for (const auto &p: m.second) {
    //                cout << "      " << p << endl;
    //            }
    //            cout << endl;
    //        }
    //
    //        // TODO: Sort???
    //
    //        // Calculations
    //        int iteration = 0;
    //        int64 total = 0;
    //        for (const auto &m: MAPS) {
    //
    //            for (const auto &p: m.second) {
    //                cout << "      " << p << endl;
    //            }
    //            cout << endl;
    //        }
    //
    //
    //        return 0ll;
  }

  // TODO: where is the big amount
  static map<string, int> parse_hand(const string &hand) {
    map<string, int> M;
    for (const char &c : hand) {
      if (c == ' ')
        break;
      M[string(1, c)]++;
    }
    return M;
  }
};
