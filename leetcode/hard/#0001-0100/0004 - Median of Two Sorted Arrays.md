# 4. Median of Two Sorted Arrays

>There are two sorted arrays **nums1** and **nums2** of size m and n respectively.
>
>Find the median of the two sorted arrays. The overall run time complexity should be $O(log(m+n))$.
>
>You may assume **nums1** and **nums2** cannot be both empty.
>
>**Example 1:**
>
>```
>nums1 = [1, 3]
>nums2 = [2]
>
>The median is 2.0
>```
>
>**Example 2:**
>
>```
>nums1 = [1, 2]
>nums2 = [3, 4]
>
>The median is (2 + 3)/2 = 2.5
>```

**Solution**

// TODO


```C++
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    if (m > n) {
      swap(nums1, nums2);
      swap(m, n);
    }
    int L = 0, R = m, x = (m + n + 1) / 2;
    while (L <= R) {
      int i = (L + R) / 2;
      int j = x - i;
      if (i < R && nums2[j - 1] > nums1[i]) {
        L = i + 1;
      } else if (i > L && nums1[i - 1] > nums2[j]) {
        R = i - 1;
      } else {
        int minn = numeric_limits<int>::min(), maxx = numeric_limits<int>::max();
        int lower = max(i == 0 ? minn : nums1[i - 1], j == 0 ? minn : nums2[j - 1]);
        if ((m + n) % 2 == 1) {
          return lower;
        }
        int upper = min(i == m ? maxx : nums1[i], j == n ? maxx : nums2[j]);
        return (lower + upper) / 2.0;
      }
    }
    return 0;
  }
};
```

