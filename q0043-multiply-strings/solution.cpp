#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    int size1 = num1.size();
    int size2 = num2.size();

    if (size1 + size2 == 0)
      return "\0";

    if (num1 == "0" || num2 == "0")
      return "0";

    vector<int> result(size1 + size2, 0);

    for (int i = size1 - 1; i >= 0; i--) {
      for (int j = size2 - 1; j >= 0; j--) {
        int mul = (num1[i] - '0') * (num2[j] - '0');

        int val_index = i + j + 1;
        int carry_index = i + j;

        int sum = result[val_index] + mul;

        result[val_index] = sum % 10;
        result[carry_index] += sum / 10;
      }
    }

    string s;
    for (int val : result) {
      if (!(s.empty() && val == 0)) {
        s.push_back(val + '0');
      }
    }

    return s;
  }
};
