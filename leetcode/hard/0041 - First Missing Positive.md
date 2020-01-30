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
    bool one = false;
    int n = nums.size();
    for (auto &num: nums) {
      if (num == 1) {
        one = true;
        break;
      }
    }
    if (!one) {
      return 1;
    }
    for (auto &num: nums) {
      if (num <= 0 || num > n) {
        num = 1;
      }
    }
    for (auto &num: nums) {
      if (nums[abs(num) - 1] > 0) {
        nums[abs(num) - 1] *= -1;
      }
    }
    for (int i = 1; i < n; i++) {
      if (nums[i] > 0) {
        return i + 1;
      }
    }
    return n + 1;
  }
};
```

