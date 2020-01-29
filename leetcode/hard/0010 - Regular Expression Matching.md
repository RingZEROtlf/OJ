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
    int m = s.length(), n = p.length();
    if (n == 0) {
      return m == 0;
    }
    bool first_match = (m != 0 && (s[0] == p[0] || p[0] == '.'));
    if (n >= 2 && p[1] == '*') {
      return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
    } else {
      return first_match && isMatch(s.substr(1), p.substr(1));
    }
  }
};
```