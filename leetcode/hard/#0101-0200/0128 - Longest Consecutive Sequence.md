# 128. Longest Consecutive Sequence

>Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
>
>Your algorithm should run in O(*n*) complexity.
>
>**Example:**
>
>```
>Input: [100, 4, 200, 1, 3, 2]
>Output: 4
>Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
>```

**Solution**

// TODO

```C++
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set;
    for (auto &num: nums) {
      set.insert(num);
    }
    int result = 0;
    for (auto &num: set) {
      if (set.find(num - 1) == set.end()) {
        int size = 1, curr = num;
        while (set.find(curr + 1) != set.end()) {
          curr += 1;
          size += 1;
        }
        result = max(result, size);
      }
    }
    return result;
  }
};
```

