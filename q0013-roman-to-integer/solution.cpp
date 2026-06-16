#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    vector<pair<string, int>> roman_map = {
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100},
        {"XC", 90},  {"L", 50},   {"XL", 40}, {"X", 10},   {"IX", 9},
        {"V", 5},    {"IV", 4},   {"I", 1}};

    int sum = 0;

    int i = 0;
    while (i < s.size()) {
      for (const auto &[key, val] : roman_map) {
        if (s.compare(i, key.size(), key) == 0) {
          sum += val;
          i += key.size();
          break;
        }
      }
    }

    return sum;
  }
};
