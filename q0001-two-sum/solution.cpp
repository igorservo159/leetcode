#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> index_val_map;
    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      if (auto it = index_val_map.find(complement); it != index_val_map.end()) {
        return (vector<int>){it->second, i};
      }
      if (index_val_map.find(nums[i]) == index_val_map.end())
        index_val_map.insert({nums[i], i});
    }
    return nums;
  }
};
