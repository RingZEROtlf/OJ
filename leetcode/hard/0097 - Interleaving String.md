# 97. Interleaving String

>Given *s1*, *s2*, *s3*, find whether *s3* is formed by the interleaving of *s1* and *s2*.
>
>**Example 1:**
>
>```
>Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
>Output: true
>```
>
>**Example 2:**
>
>```
>Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
>Output: false
>```

**Solution**

// TODO

```C++
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
    if (n1 + n2 != n3) {
      return false;
    } else if (n1 == 0 && n2 == 0 && n3 == 0) {
      return true;
    }
    vector<bool> curr(n2 + 1);
    curr[0] = true;
    for (int i = 1; i <= n2; i++) {
      curr[i] = curr[i - 1] && (s2[i - 1] == s3[i - 1]);
    }
    vector<bool> prev { curr };
    for (int i = 1; i <= n1; i++) {
      swap(prev, curr);
      curr[0] = prev[0] && (s1[i - 1] == s3[i - 1]);
      for (int j = 1; j <= n2; j++) {
        curr[j] = (curr[j - 1] && (s2[j - 1] == s3[i + j - 1])) || (prev[j] && (s1[i - 1] == s3[i + j - 1]));
      }
    }
    return curr.back();
  }
};
```

