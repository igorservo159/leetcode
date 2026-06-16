int reverse(int x){
  int digit;
  int reverseNum = 0;

  while (x != 0) {
    digit = x % 10;

    if (reverseNum > INT_MAX / 10 || (reverseNum == INT_MAX / 10 && digit > 7))
      return 0;
    if (reverseNum < INT_MIN / 10 || (reverseNum == INT_MIN / 10 && digit < -8))
      return 0;

    reverseNum = reverseNum * 10 + digit;
    x /= 10;
  }

  return reverseNum;
}
