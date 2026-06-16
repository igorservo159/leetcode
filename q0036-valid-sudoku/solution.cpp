#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<vector<bool>> rows(9, vector<bool>(9, false));
    vector<vector<bool>> cols(9, vector<bool>(9, false));
    vector<vector<bool>> blocks(9, vector<bool>(9, false));

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.')
          continue;
        int num = board[i][j] - '1';
        int boxIndex = (i / 3) * 3 + (j / 3);

        if (rows[i][num] || cols[j][num] || blocks[boxIndex][num])
          return false;
        rows[i][num] = cols[j][num] = blocks[boxIndex][num] = true;
      }
    }
    return true;
  }
};

int main() {
  vector<vector<char>> board = {
      {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  cout << "board[1][2] = " << board[1][2];
}
