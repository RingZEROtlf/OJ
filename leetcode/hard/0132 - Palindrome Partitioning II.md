# 132. Palindrome Partitioning II

>Given a string *s*, partition *s* such that every substring of the partition is a palindrome.
>
>Return the minimum cuts needed for a palindrome partitioning of *s*.
>
>**Example:**
>
>```
>Input: "aab"
>Output: 1
>Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
>```

**Solution**

// TODO

```C++
class Solution {
public:
  int minCut(string s) {
    int n = s.length();
    int dp[n];
    bool is_p[n][n];
    for (int i = 0; i < n; i += 1) {
      dp[i] = numeric_limits<int>::max();
      for (int j = 0; j <= i; j += 1) {
        if (s[i] == s[j]) {
          is_p[j][i] = (i - j <= 1 ? true : is_p[j + 1][i - 1]);
        } else {
          is_p[j][i] = false;
        }
        if (is_p[j][i]) {
          dp[i] = min(dp[i], j > 0 ? dp[j - 1] + 1 : 0);
        }
      }
    }
    return dp[n - 1];
  }
};
```

