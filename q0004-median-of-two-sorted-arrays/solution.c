#define MININT -99999999
#define MAXINT 99999999

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  //Check if nums1 is smaller than nums2
  int *a = NULL;
  int *b = NULL;
  int aSize;
  int bSize;
  if (nums1Size <= nums2Size) {
    a = nums1;
    b = nums2;
    aSize = nums1Size;
    bSize = nums2Size;
  } else {
    a = nums2;
    b = nums1;
    aSize = nums2Size;
    bSize = nums1Size;
  }

  int left = 0;
  int right = aSize;
  int half = (aSize + bSize + 1) / 2;

  while (left <= right){
    int i = (left + right) / 2;
    int j = half - i;

    int a_left = (i == 0) ? MININT : a[i-1];
    int a_right = (i == aSize) ? MAXINT : a[i];
    int b_left = (j == 0) ? MININT : b[j-1];
    int b_right = (j == bSize) ? MAXINT : b[j];

    if (a_left <= b_right && a_right >= b_left) {
      if ((aSize + bSize) % 2 == 0) {
        double lmax = (a_left >= b_left) ? a_left : b_left;
        double rmin = (a_right >= b_right) ? b_right : a_right;
        return (lmax + rmin) / 2.0;
      } else {
        return (a_left >= b_left) ? (double)a_left : (double)b_left;
      }
    }
    else if (a_left >= b_right) {
      right = i - 1;
    }
    else{
      left = i + 1;
    }
  }
  return 0.0; 
}
