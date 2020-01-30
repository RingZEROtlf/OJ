# 37. Sudoku Solver

>Write a program to solve a Sudoku puzzle by filling the empty cells.
>
>A sudoku solution must satisfy **all of the following rules**:
>
>1. Each of the digits `1-9` must occur exactly once in each row.
>2. Each of the digits `1-9` must occur exactly once in each column.
>3. Each of the the digits `1-9` must occur exactly once in each of the 9 `3x3` sub-boxes of the grid.
>
>Empty cells are indicated by the character `'.'`.
>
>![img](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)
>A sudoku puzzle...
>
>![img](https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)
>...and its solution numbers marked in red.
>
>**Note:**
>
>- The given board contain only digits `1-9` and the character `'.'`.
>- You may assume that the given Sudoku puzzle will have a single unique solution.
>- The given board size is always `9x9`.

**Solution**

// TODO

```C++
class Solution {
public:
  void solveSudoku(vector<vector<char>>& board) {
    _solveSudoku(board);
  }
  
  bool _solveSudoku(vector<vector<char>>& board) {
    if (isDone(board)) {
      return true;
    }
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        if (board[row][col] == '.') {
          for (int value = 1; value <= 9; value++) {
            if (isValid(board, row, col, value)) {
              board[row][col] = '0' + value;
              if (_solveSudoku(board)) {
                return true;
              }
            }
          }
          board[row][col] = '.';
          return false;
        }
      }
    }
    return false;
  }
  
  bool isDone(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        if (board[row][col] == '.') {
          return false;
        }
      }
    }
    return true;
  }
  
  bool isValid(vector<vector<char>>& board, int row, int col, int value) {
    for (int i = 0; i < 9; i++) {
      if (i != row && board[i][col] == '0' + value) {
        return false;
      }
      if (i != col && board[row][i] == '0' + value) {
        return false;
      }
      int r = row / 3 * 3 + i / 3, c = col / 3 * 3 + i % 3;
      if (r != row && c != col && board[r][c] == '0' + value) {
        return false;
      }
    }
    return true;
  }
};
```

