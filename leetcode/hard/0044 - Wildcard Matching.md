# 44. Wildcard Matching

>Given an input string (`s`) and a pattern (`p`), implement wildcard pattern matching with support for `'?'` and `'*'`.
>
>```
>'?' Matches any single character.
>'*' Matches any sequence of characters (including the empty sequence).
>```
>
>The matching should cover the **entire** input string (not partial).
>
>**Note:**
>
>- `s` could be empty and contains only lowercase letters `a-z`.
>- `p` could be empty and contains only lowercase letters `a-z`, and characters like `?` or `*`.
>
>**Example 1:**
>
>```
>Input:
>s = "aa"
>p = "a"
>Output: false
>Explanation: "a" does not match the entire string "aa".
>```
>
>**Example 2:**
>
>```
>Input:
>s = "aa"
>p = "*"
>Output: true
>Explanation: '*' matches any sequence.
>```
>
>**Example 3:**
>
>```
>Input:
>s = "cb"
>p = "?a"
>Output: false
>Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
>```
>
>**Example 4:**
>
>```
>Input:
>s = "adceb"
>p = "*a*b"
>Output: true
>Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
>```
>
>**Example 5:**
>
>```
>Input:
>s = "acdcb"
>p = "a*c?b"
>Output: false
>```

**Solution**

// TODO

```C++
class Solution {
public:
  bool isMatch(string s, string p) {
    vector<bool> dp(p.length() + 1);
    dp[0] = true;
    for (int i = 1; i <= p.length(); i++) {
      if (p[i - 1] == '*') {
        dp[i] = dp[i - 1];
      }
    }
    auto prev { dp };
    for (int i = 1; i <= s.length(); i++) {
      dp[0] = false;
      for (int j = 1; j <= p.length(); j++) {
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
          dp[j] = prev[j - 1];
        } else if (p[j - 1] == '*') {
          dp[j] = dp[j - 1] || prev[j];
        } else {
          dp[j] = false;
        }
      }
      swap(prev, dp);
    }
    return prev.back();
  }
};
```

