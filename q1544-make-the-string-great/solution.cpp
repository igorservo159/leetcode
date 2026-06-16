#include <string>

using namespace std;

class Solution {
public:
  string makeGood(string s) {
    string stack = "";

    int lower_upper_difference = 'A' - 'a';

    for (char c : s) {
      if (!stack.empty() && (stack.back() - c == lower_upper_difference ||
                             stack.back() - c == lower_upper_difference * (-1)))
        stack.pop_back();

      else
        stack.push_back(c);
    }

    return stack;
  }
};
