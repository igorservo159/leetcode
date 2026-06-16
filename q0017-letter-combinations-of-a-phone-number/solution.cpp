#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    string current;
    backtrack(digits, 0, current, res);
    return res;
  }

private:
  unordered_map<char, string> phone_map = {
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

  void backtrack(const string &digits, int index, string &current,
                 vector<string> &res) {

    if (index == digits.size()) {
      res.push_back(current);
      return;
    }

    string letters = phone_map[digits[index]];
    for (char letter : letters) {
      current.push_back(letter);
      backtrack(digits, index + 1, current, res);
      current.pop_back();
    }
  }
};
