#include <string>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    // return haystack.find(needle);

    if (needle.size() > haystack.size())
      return -1;

    int j = 0;
    int i = 0;
    while (i <= haystack.size() - needle.size()) {
      while (i + j < haystack.size() && haystack[i + j] == needle[j]) {
        j++;
      }
      if (j == needle.size())
        return i;
      j = 0;
      i++;
    }

    return -1;
  }
};
