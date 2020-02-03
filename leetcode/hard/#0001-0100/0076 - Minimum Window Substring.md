# 76. Minimum Window Substring

>Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
>
>**Example:**
>
>```
>Input: S = "ADOBECODEBANC", T = "ABC"
>Output: "BANC"
>```
>
>**Note:**
>
>- If there is no such window in S that covers all characters in T, return the empty string `""`.
>- If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

**Solution**

// TODO

```C++
class Solution {
public:
  string minWindow(string s, string t) {
    map<char, int> dictT;
    for (int i = 0; i < t.length(); i += 1) {
      dictT[t[i]] += 1;
    }
    int required = dictT.size(), formed = 0;
    int L = 0, R = 0, ans[2] = { -1, 0 };
    map<char, int> dictWindow;
    while (R < s.length()) {
      dictWindow[s[R]] += 1;
      if (dictT[s[R]] == dictWindow[s[R]]) {
        formed += 1;
      }
      while (L <= R && formed == required) {
        if (ans[0] == -1 || R - L + 1 < ans[0]) {
          ans[0] = R - L + 1;
          ans[1] = L;
        }
        dictWindow[s[L]] -= 1;
        if (dictT[s[L]] > dictWindow[s[L]]) {
          formed -= 1;
        }
        L += 1;
      }
      R += 1;
    }
    return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
  }
};
```

