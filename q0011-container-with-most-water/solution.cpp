#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int biggestArea = 0;

    while (left != right) {
      int tmpArea = (right - left) * min(height[left], height[right]);
      if (tmpArea > biggestArea)
        biggestArea = tmpArea;
      if (height[left] >= height[right])
        right--;
      else
        left++;
    }
    return biggestArea;
  }
};
