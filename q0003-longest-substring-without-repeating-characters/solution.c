int lengthOfLongestSubstring(char* s) {
  //Create the vector with the indexes of last seen positions of a char and initialize it with -1
  int index;
  int *lastCharIndexes = malloc(sizeof(int) * 256);
  for (int i = 0; i < 256; i++) {
    lastCharIndexes[i] = -1;
  }

  int longestWindowLength = 0;
  int left = 0;
  int i = 0;
  int key;

  while(s[i] != '\0') {
    key = s[i];
    if (lastCharIndexes[key] >= left){
      left = lastCharIndexes[key] + 1;
    }
    lastCharIndexes[key] = i;
    longestWindowLength = (i + 1 - left > longestWindowLength) ? i + 1 - left : longestWindowLength;
    i++;
  }

  return longestWindowLength;
}
