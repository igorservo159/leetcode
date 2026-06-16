#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string removeDuplicateLetters(string s) {
    string stack = "";
    vector<int> count(26, 0);
    vector<bool> is_in_stack(26, false);
    for (char c : s)
      count[c - 'a']++;

    for (char c : s) {
      count[c - 'a']--;

      if (is_in_stack[c - 'a'])
        continue;

      while (!stack.empty() && c < stack.back() &&
             count[stack.back() - 'a'] > 0) {
        is_in_stack[stack.back() - 'a'] = false;
        stack.pop_back();
      }

      stack.push_back(c);
      is_in_stack[c - 'a'] = true;

      cout << stack << endl;
    }

    return stack;
  }
};

int main() {
  string s = "bcdeae";
  Solution solution;
  solution.removeDuplicateLetters(s);
}
