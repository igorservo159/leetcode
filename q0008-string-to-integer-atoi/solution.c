#include <limits.h>
int myAtoi(char *s) {
  int i = 0;
  int res = 0;
  int sign = 1;

  while (s[i] == ' ')
    i++;

  if (s[i] == '-' || s[i] == '+') {
    if (s[i] == '-') {
      sign = -1;
    }
    i++;
  }

  // while (s[i] == '0') i++;

  int digit;
  while (s[i] != '\0') {
    if (s[i] < '0' || s[i] > '9')
      break;

    digit = s[i] - '0';

    if (sign == 1 &&
        (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit >= 7)))
      return INT_MAX;
    if (sign == -1 &&
        (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit >= 8)))
      return INT_MIN;

    res = res * 10 + digit;
    i++;
  }

  return sign * res;
}
