# 85. Maximal Rectangle

>Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
>
>**Example:**
>
>```
>Input:
>[
>  ["1","0","1","0","0"],
>  ["1","0","1","1","1"],
>  ["1","1","1","1","1"],
>  ["1","0","0","1","0"]
>]
>Output: 6
>```

**Solution**

// TODO

```C++
class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.size() == 0) {
      return 0;
    }
    int rows = matrix.size(), cols = matrix[0].size(), ans = 0;
    vector<int> bars(cols, 0);
    for (int row = 0; row < rows; row += 1) {
      for (int col = 0; col < cols; col += 1) {
        if (matrix[row][col] == '1') {
          bars[col] += 1;
        } else {
          bars[col] = 0;
        }
      }
      stack<int> stack;
      int idx = 0;
      while (idx < bars.size() || !stack.empty()) {
        if (stack.empty() || (idx < bars.size() && bars[stack.top()] <= bars[idx])) {
          stack.push(idx);
          idx += 1;
        } else {
          int iidx = stack.top();
          stack.pop();
          ans = max(ans, bars[iidx] * (stack.empty() ? idx : idx - stack.top() - 1));
        }
      }
    }
    return ans;
  }
};
```

