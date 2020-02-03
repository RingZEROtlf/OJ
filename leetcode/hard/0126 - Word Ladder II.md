# 126. Word Ladder II

>Given two words (*beginWord* and *endWord*), and a dictionary's word list, find all shortest transformation sequence(s) from *beginWord* to *endWord*, such that:
>
>1. Only one letter can be changed at a time
>2. Each transformed word must exist in the word list. Note that *beginWord* is *not* a transformed word.
>
>**Note:**
>
>- Return an empty list if there is no such transformation sequence.
>- All words have the same length.
>- All words contain only lowercase alphabetic characters.
>- You may assume no duplicates in the word list.
>- You may assume *beginWord* and *endWord* are non-empty and are not the same.
>
>**Example 1:**
>
>```
>Input:
>beginWord = "hit",
>endWord = "cog",
>wordList = ["hot","dot","dog","lot","log","cog"]
>
>Output:
>[
>  ["hit","hot","dot","dog","cog"],
>  ["hit","hot","lot","log","cog"]
>]
>```
>
>**Example 2:**
>
>```
>Input:
>beginWord = "hit"
>endWord = "cog"
>wordList = ["hot","dot","dog","lot","log"]
>
>Output: []
>
>Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
>```

**Solution**

// TODO

```C++
class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    auto expand = [&](string &word) {
      vector<string> ret;
      for (int i = 0; i < word.size(); i += 1) {
        char old = word[i];
        for (word[i] = 'a'; word[i] <= 'z'; word[i] += 1) {
          if (word[i] != old && dict.find(word) != dict.end()) {
            ret.push_back(word);
          }
        }
        word[i] = old;
      }
      return ret;
    };
    
    queue<vector<string>> q;
    q.push({beginWord});
    vector<vector<string>> results;
    while (!q.empty() && results.empty()) {
      unordered_set<string> seen;
      for (int i = q.size() - 1; i >= 0; i -= 1) {
        auto path = q.front(); q.pop();
        auto nextWords = expand(path.back());
        for (auto &word: nextWords) {
          path.push_back(word);
          if (word == endWord) {
            results.push_back(path);
          } else {
            q.push(path);
          }
          seen.insert(word);
          path.pop_back();
        }
      }
      for (auto &word: seen) {
        dict.erase(word);
      }
    }
    return results;
  }
};
```

