# 42. Trapping Rain Water

>Given *n* non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
>
>![img](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)
>The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. **Thanks Marcos** for contributing this image!
>
>**Example:**
>
>```
>Input: [0,1,0,2,1,0,1,3,2,1,2,1]
>Output: 6
>```

**Solution**

// TODO

```C++
class Solution {
public:
  int trap(vector<int>& height) {
    int ans = 0, size = height.size();
    if (size == 0) {
      return 0;
    }
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; i++) {
      left_max[i] = max(height[i], left_max[i - 1]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
      right_max[i] = max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < size - 1; i++) {
      ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
  }
};
```

