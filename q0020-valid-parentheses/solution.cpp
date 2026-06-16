#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    string stack = "";

    for (char c : s) {
      if (c == '(' || c == '[' || c == '{')
        stack.push_back(c);
      else {
        if (stack.empty())
          return false;
        else if (stack.back() == '(' && c != ')')
          return false;
        else if (stack.back() == '{' && c != '}')
          return false;
        else if (stack.back() == '[' && c != ']')
          return false;
        else
          stack.pop_back();
      }
    }

    return stack.empty();
  }
};
