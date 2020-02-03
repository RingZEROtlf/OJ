# 51. N-Queens

>The *n*-queens puzzle is the problem of placing *n* queens on an *n*×*n* chessboard such that no two queens attack each other.
>
>![img](https://assets.leetcode.com/uploads/2018/10/12/8-queens.png)
>
>Given an integer *n*, return all distinct solutions to the *n*-queens puzzle.
>
>Each solution contains a distinct board configuration of the *n*-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space respectively.
>
>**Example:**
>
>```
>Input: 4
>Output: [
> [".Q..",  // Solution 1
>  "...Q",
>  "Q...",
>  "..Q."],
>
> ["..Q.",  // Solution 2
>  "Q...",
>  "...Q",
>  ".Q.."]
>]
>Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
>```

**Solution**

// TODO

```C++
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    _solveNQueens(result, board, n, 0);
    return result;
  }
  
  void _solveNQueens(vector<vector<string>> &result, vector<string> &board, int n, int row) {
    if (row == n) {
      result.push_back(board);
      return;
    }
    for (int col = 0; col < n; col++) {
      if (isValid(board, n, row, col)) {
        board[row][col] = 'Q';
        _solveNQueens(result, board, n, row + 1);
        board[row][col] = '.';
      }
    }
  }
  
  bool isValid(vector<string> &board, int n, int row, int col) {
    for (int i = 0; i < n; i++) {
      if (i != row && board[i][col] == 'Q') {
        return false;
      } else if (i != col && board[row][i] == 'Q') {
        return false;
      } else if (!check(board, n, row, col, row - i, col - i)) {
        return false;
      } else if (!check(board, n, row, col, row - i, col + i)) {
        return false;
      } else if (!check(board, n, row, col, row + i, col - i)) {
        return false;
      } else if (!check(board, n, row, col, row + i, col + i)) {
        return false;
      }
    }
    return true;
  }
  
  bool check(vector<string> &board, int n, int row, int col, int r, int c) {
    return (r == row && c == col) || r < 0 || r >= n || c < 0 || c >= n || board[r][c] == '.';
  }
};
```

