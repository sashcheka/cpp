class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int rows[9][9] = {0};
    int cols[9][9] = {0};
    int boxes[9][9] = {0};
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') {
          continue;
        }
        int index = board[i][j] - '1';
        int k = i / 3 * 3 + j / 3;
        if (rows[i][index]++ || cols[j][index]++ || boxes[k][index]++) {
          return false;
        }
      }
    }
    return true;
  }
};