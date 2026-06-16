#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    int total = 0;

    sort(
        boxTypes.begin(), boxTypes.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] > b[1]; });

    while (truckSize > 0 && !boxTypes.empty()) {
      total += boxTypes.front()[1];

      if (boxTypes.front()[0] == 1)
        boxTypes.erase(boxTypes.begin());
      else
        boxTypes.front()[0]--;
      truckSize--;
    }

    return total;
  }
};
