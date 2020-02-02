# 115. Distinct Subsequences

>Given a string **S** and a string **T**, count the number of distinct subsequences of **S** which equals **T**.
>
>A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, `"ACE"` is a subsequence of `"ABCDE"` while `"AEC"` is not).
>
>**Example 1:**
>
>```
>Input: S = "rabbbit", T = "rabbit"
>Output: 3
>Explanation:
>
>As shown below, there are 3 ways you can generate "rabbit" from S.
>(The caret symbol ^ means the chosen letters)
>
>rabbbit
>^^^^ ^^
>rabbbit
>^^ ^^^^
>rabbbit
>^^^ ^^^
>```
>
>**Example 2:**
>
>```
>Input: S = "babgbag", T = "bag"
>Output: 5
>Explanation:
>
>As shown below, there are 5 ways you can generate "bag" from S.
>(The caret symbol ^ means the chosen letters)
>
>babgbag
>^^ ^
>babgbag
>^^    ^
>babgbag
>^    ^^
>babgbag
>  ^  ^^
>babgbag
>    ^^^
>```

**Solution**

// TODO

```C++
class Solution {
public:
  int numDistinct(string s, string t) {
    int ss = s.length(), tt = t.length();
    vector<int> curr(ss + 1), prev(ss + 1);
    for (int i = 1; i <= ss; i += 1) {
      curr[i] = s[i - 1] == t[0] ? 1 : 0;
    }
    for (int i = 2; i <= tt; i += 1) {
      swap(curr, prev);
      int64_t sum = 0;
      for (int j = 1; j <= ss; j += 1) {
        curr[j] = s[j - 1] == t[i - 1] ? sum : 0;
        sum += prev[j];
      }
    }
    int sum = 0;
    for (auto &v: curr) {
      sum += v;
    }
    return sum;
  }
};
```

