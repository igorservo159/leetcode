#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int right = nums.size() - 1;
    int left = 0;

    while (right - left >= 0) {
      int half = left + (right - left) / 2;
      if (target == nums[half])
        return half;
      else if (target > nums[half])
        left = half + 1;
      else
        right = half - 1;
    }
    return left;
  }
};
