#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    int n = tasks.size();

    vector<vector<int>> indexed(n);
    for (int j = 0; j < n; j++) {
      indexed[j] = {tasks[j][0], tasks[j][1], j};
    }

    sort(indexed.begin(), indexed.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> available;

    vector<int> result;
    int currentTime = 0;
    int i = 0;

    while (i < n || !available.empty()) {
      if (available.empty() && currentTime < indexed[i][0]) {
        currentTime = indexed[i][0];
      }

      while (i < n && indexed[i][0] <= currentTime) {
        available.push({indexed[i][1], indexed[i][2]});
        i++;
      }

      auto [process, idx] = available.top();
      available.pop();
      result.push_back(idx);
      currentTime += process;
    }

    return result;
  }
};
