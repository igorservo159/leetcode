#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int write_index = 0;
    for (int num : nums) {
      if (num != val) {
        nums[write_index++] = num;
      }
    }
    return write_index;
  }
};
