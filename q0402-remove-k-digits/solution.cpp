// #include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
    if (k > num.size())
      return "0";
    string stack = "";

    for (char digit : num) {
      while (!stack.empty() && digit < stack.back() && k > 0) {
        stack.pop_back();
        k--;
      }

      stack.push_back(digit);
    }

    while (!stack.empty() && stack.front() == '0')
      stack.erase(0, 1);

    if (k >= stack.size())
      return "0";

    if (k > 0)
      stack.erase(stack.size() - k, k);

    if (stack.empty())
      return "0";

    return stack;
  }
};

int main() {
  Solution solution;
  solution.removeKdigits("10200", 1);
}
