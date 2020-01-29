# 30. Substring with Concatenation of All Words

>You are given a string, **s**, and a list of words, **words**, that are all of the same length. Find all starting indices of substring(s) in **s** that is a concatenation of each word in **words** exactly once and without any intervening characters.
>
> 
>
>**Example 1:**
>
>```
>Input:
>  s = "barfoothefoobarman",
>  words = ["foo","bar"]
>Output: [0,9]
>Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
>The output order does not matter, returning [9,0] is fine too.
>```
>
>**Example 2:**
>
>```
>Input:
>  s = "wordgoodgoodgoodbestword",
>  words = ["word","good","best","word"]
>Output: []
>```

**Solution**

// TODO

```C++
class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    
    if (s.length() == 0 || words.size() == 0) {
      return result;
    }
    
    int word_length = words[0].length();
    int total_length = word_length * words.size();
    
    map<string, int> words_count;
    int ascii_count = 0;
    for (auto &word: words) {
      words_count[word]++;
      for (auto &c: word) {
        ascii_count += c;
      }
    }
    
    for (int i = 0; i <= (int) s.length() - total_length; i++) {
      string sub = s.substr(i, total_length);
      int count = 0;
      for (auto &c: sub) {
        count += c;
      }
      if (count != ascii_count) {
        continue;
      }
      
      bool flag = true;
      auto temp_count = words_count;
      for (int j = 0; j < sub.length(); j += word_length) {
        auto word = sub.substr(j, word_length);
        if (temp_count.find(word) == temp_count.end()) {
          flag = false;
          break;
        }
        temp_count[word]--;
        if (temp_count[word] == 0) {
          temp_count.erase(word);
        }
      }
      if (flag && temp_count.empty()) {
        result.push_back(i);
      }
    }
    return result;
  }
};
```

注意第22行会有隐式类型转换造成如下测试用例失败

```
"a"
["a","a"]
```

