# 87. Scramble String

>Given a string *s1*, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
>
>Below is one possible representation of *s1* = `"great"`:
>
>```
>    great
>   /    \
>  gr    eat
> / \    /  \
>g   r  e   at
>           / \
>          a   t
>```
>
>To scramble the string, we may choose any non-leaf node and swap its two children.
>
>For example, if we choose the node `"gr"` and swap its two children, it produces a scrambled string `"rgeat"`.
>
>```
>    rgeat
>   /    \
>  rg    eat
> / \    /  \
>r   g  e   at
>           / \
>          a   t
>```
>
>We say that `"rgeat"` is a scrambled string of `"great"`.
>
>Similarly, if we continue to swap the children of nodes `"eat"` and `"at"`, it produces a scrambled string `"rgtae"`.
>
>```
>    rgtae
>   /    \
>  rg    tae
> / \    /  \
>r   g  ta  e
>       / \
>      t   a
>```
>
>We say that `"rgtae"` is a scrambled string of `"great"`.
>
>Given two strings *s1* and *s2* of the same length, determine if *s2* is a scrambled string of *s1*.
>
>**Example 1:**
>
>```
>Input: s1 = "great", s2 = "rgeat"
>Output: true
>```
>
>**Example 2:**
>
>```
>Input: s1 = "abcde", s2 = "caebd"
>Output: false
>```

**Solution**

// TODO

```C++
class Solution {
public:
  bool isScramble(string s1, string s2) {
    int n = s1.length();
    return _isScramble(s1, 0, n, s2, 0, n);
  }
  
  bool _isScramble(string &s1, int L1, int R1, string &s2, int L2, int R2) {
    if (L1 + 1 == R1) {
      return s1[L1] == s2[L2];
    } else {      
      int n = R1 - L1;
      map<char, int> d1, d2;
      for (int i = 0; i < n; i += 1) {
        d1[s1[L1 + i]] += 1;
        d2[s2[L2 + i]] += 1;
      }
      for (auto &entry: d1) {
        if (d2[entry.first] != entry.second) {
          return false;
        }
      }
      for (auto &entry: d2) {
        if (d1[entry.first] != entry.second) {
          return false;
        }
      }
      for (int i = 1; i < n; i += 1) {
        if (_isScramble(s1, L1, L1 + i, s2, L2, L2 + i) && _isScramble(s1, L1 + i, R1, s2, L2 + i, R2)) {
          return true;
        } else if (_isScramble(s1, R1 - i, R1, s2, L2, L2 + i) && _isScramble(s1, L1, R1 - i, s2, L2 + i, R2)) {
          return true;
        }
      }
      return false;
    }
  }
};
```

