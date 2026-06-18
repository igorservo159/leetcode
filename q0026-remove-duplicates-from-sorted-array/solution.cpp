#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int write_index = 0;
    for (int num : nums) {
      if (write_index == 0 || num != nums[write_index - 1]) {
        nums[write_index++] = num;
      }
    }
    return write_index;
  }
};
