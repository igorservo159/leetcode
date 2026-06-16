char* convert(char* s, int numRows) {
  //unique row case
  if (numRows == 1) return s;

  //Get string size
  int cycleLen = numRows * 2 - 2;
  int stringSize = 0;
  while (s[stringSize] != '\0') stringSize++;

  //Alloc char "matrix"
  char **mapRows = malloc(numRows * sizeof(char*));
  int maxColumnsNum = (stringSize / cycleLen + 1) * 2;
  char *map = calloc(numRows * (maxColumnsNum), 1);
  for (int i = 0; i < numRows; i++) {
    mapRows[i] = map + maxColumnsNum * i;
  }

  //Put string in matrix
  int index = 0;
  int groupIndex = 0;
  int *freeRowPosition = calloc(numRows, sizeof(int));
  while(s[index] != '\0') {
    if (groupIndex / numRows == 0) {
      mapRows[groupIndex][freeRowPosition[groupIndex]] = s[index];
      freeRowPosition[groupIndex]++;
    } else {
      int row = cycleLen - groupIndex;
      mapRows[row][freeRowPosition[row]] = s[index]; 
      freeRowPosition[row]++;
    }
    index++;
    groupIndex = (groupIndex + 1) % cycleLen;
  }

  index = 0;
  char *res = malloc(stringSize + 1);
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < freeRowPosition[i]; j++) {
      res[index] = mapRows[i][j];
      index++;
    }
  }
  res[stringSize] = '\0';

  free(freeRowPosition);
  free(map);
  free(mapRows);

  return res;
}
