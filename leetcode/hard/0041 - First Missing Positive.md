# 41. First Missing Positive

>Given an unsorted integer array, find the smallest missing positive integer.
>
>**Example 1:**
>
>```
>Input: [1,2,0]
>Output: 3
>```
>
>**Example 2:**
>
>```
>Input: [3,4,-1,1]
>Output: 2
>```
>
>**Example 3:**
>
>```
>Input: [7,8,9,11,12]
>Output: 1
>```
>
>**Note:**
>
>Your algorithm should run in *O*(*n*) time and uses constant extra space.

**Solution**

// TODO

```C++
class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i += 1) {
      int j = nums[i];
      while (0 < j && j <= n) {
        if (nums[j - 1] == j) {
          break;
        } else {
          swap(nums[j - 1], j);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return n + 1;
  }
};
```

