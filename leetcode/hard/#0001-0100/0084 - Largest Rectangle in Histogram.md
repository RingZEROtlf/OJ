# 84. Largest Rectangle in Histogram

>Given *n* non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
>
> 
>
>![img](https://assets.leetcode.com/uploads/2018/10/12/histogram.png)
>Above is a histogram where width of each bar is 1, given height = `[2,1,5,6,2,3]`.
>
> 
>
>![img](https://assets.leetcode.com/uploads/2018/10/12/histogram_area.png)
>The largest rectangle is shown in the shaded area, which has area = `10` unit.
>
> 
>
>**Example:**
>
>```
>Input: [2,1,5,6,2,3]
>Output: 10
>```

**Solution**

// TODO

```C++
class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    stack<int> stack;
    int ans = 0, idx = 0;
    while (idx < heights.size() || !stack.empty()) {
      if (stack.empty() || (idx < heights.size() && heights[stack.top()] <= heights[idx])) {
        stack.push(idx);
        idx += 1;
      } else {
        int iidx = stack.top();
        stack.pop();
        ans = max(ans, heights[iidx] * (stack.empty() ? idx : idx - stack.top() - 1));
      }
    }
    return ans;
  }
};
```

