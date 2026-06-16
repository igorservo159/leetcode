#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int minSetSize(vector<int> &arr) {
    unordered_map<int, int> freq_hash;

    for (int num : arr)
      freq_hash[num]++;

    vector<pair<int, int>> ordered_freq(freq_hash.begin(), freq_hash.end());

    sort(ordered_freq.begin(), ordered_freq.end(),
         [](pair<int, int> &a, pair<int, int> &b) {
           return a.second > b.second;
         });

    int removedCount = 0;
    int groupRemovedCount = 0;

    while (removedCount < arr.size() / 2) {
      removedCount += ordered_freq[groupRemovedCount].second;
      groupRemovedCount++;
    }

    return groupRemovedCount;
  }
};
