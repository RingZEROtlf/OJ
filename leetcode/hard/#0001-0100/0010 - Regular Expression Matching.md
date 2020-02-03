# 10. Regular Expression Matching

>Given an input string (`s`) and a pattern (`p`), implement regular expression matching with support for `'.'` and `'*'`.
>
>```
>'.' Matches any single character.
>'*' Matches zero or more of the preceding element.
>```
>
>The matching should cover the **entire** input string (not partial).
>
>**Note:**
>
>- `s` could be empty and contains only lowercase letters `a-z`.
>- `p` could be empty and contains only lowercase letters `a-z`, and characters like `.` or `*`.
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
>p = "a*"
>Output: true
>Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
>```
>
>**Example 3:**
>
>```
>Input:
>s = "ab"
>p = ".*"
>Output: true
>Explanation: ".*" means "zero or more (*) of any character (.)".
>```
>
>**Example 4:**
>
>```
>Input:
>s = "aab"
>p = "c*a*b"
>Output: true
>Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
>```
>
>**Example 5:**
>
>```
>Input:
>s = "mississippi"
>p = "mis*is*p*."
>Output: false
>```

**Solution**

// TODO

```C++
class Solution {
public:
  bool isMatch(string s, string p) {
    return _isMatch(s, p, s.length(), p.length(), 0, 0);
  }
  
  bool _isMatch(string &s, string &p, int sl, int pl, int si, int pi) {
    if (pi == pl) {
      return si == sl;
    }
    bool firstMatch = (si != sl && (s[si] == p[pi] || p[pi] == '.'));
    if (pl - pi >= 2 && p[pi + 1] == '*') {
      return _isMatch(s, p, sl, pl, si, pi + 2) || (firstMatch && _isMatch(s, p, sl, pl, si + 1, pi));
    } else {
      return firstMatch && _isMatch(s, p, sl, pl, si + 1, pi + 1);
    }
  }
};
```