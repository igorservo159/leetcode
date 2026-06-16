char* longestPalindrome(char* s) {
  char *itrChar = s;
  char *longestPalindromeStart = NULL;
  int longestPalindromeSize = 0;

  while (*itrChar != '\0') {
    //Odd Palindrome
    char *left = itrChar - 1;
    char *right = itrChar + 1;
    int palindromeSize = 1;

    while (left >= s && *right != '\0') {
      if (*left == *right){
        left--;
        right++;
        palindromeSize += 2;
      }
      else {
        break;
      }
    }

    //Check if the odd palindrome is bigger than the biggest one til now
    if (palindromeSize > longestPalindromeSize) {
      longestPalindromeSize = palindromeSize;
      longestPalindromeStart = left + 1;
    }

    //Even Palindrome
    if(*itrChar == *(itrChar + 1)) {
      char *left = itrChar - 1;
      char *right = itrChar + 2;
      int palindromeSize = 2;

      while (left >= s && *right != '\0') {
        if (*left == *right){
          left--;
          right++;
          palindromeSize += 2;
        }
        else {
          break;
        }
      }

      if (palindromeSize > longestPalindromeSize) {
        longestPalindromeSize = palindromeSize;
        longestPalindromeStart = left + 1;
      }
    }

    itrChar++;
  }

  longestPalindromeStart[longestPalindromeSize] = '\0';
  return longestPalindromeStart;
}
