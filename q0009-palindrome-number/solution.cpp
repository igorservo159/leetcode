class Solution {
public:
  bool isPalindrome(int x) {

    if (x < 0)
      return false;

    int tmp = x;
    int reverse = 0;

    while (tmp > 0) {
      int digit = tmp % 10;

      if (reverse > 214748364 || (reverse == 214748364 && digit > 7))
        return false;

      reverse = 10 * reverse + digit;
      tmp /= 10;
    }

    return reverse == x;
  }
};
