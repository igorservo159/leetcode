#include <unordered_set>

using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> seen_before_set;

    while (n != 1) {
      if (seen_before_set.find(n) != seen_before_set.end())
        return false;
      seen_before_set.insert(n);

      int sum = 0;

      while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
      }

      n = sum;
    }

    return n == 1;
  }
};
