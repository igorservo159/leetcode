#include <vector>

using namespace std;

class Solution {
public:
  int findGCD(vector<int> &nums) {
    int max_num = 0;
    int min_num = 1001;
    for (int num : nums) {
      if (num > max_num)
        max_num = num;
      if (num < min_num)
        min_num = num;
    }

    while (min_num > 0) {
      int aux = min_num;
      min_num = max_num % min_num;
      max_num = aux;
    }

    return max_num;
  }
};
