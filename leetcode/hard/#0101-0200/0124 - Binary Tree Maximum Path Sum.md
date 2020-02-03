# 124. Binary Tree Maximum Path Sum

>Given a **non-empty** binary tree, find the maximum path sum.
>
>For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain **at least one node** and does not need to go through the root.
>
>**Example 1:**
>
>```
>Input: [1,2,3]
>
>       1
>      / \
>     2   3
>
>Output: 6
>```
>
>**Example 2:**
>
>```
>Input: [-10,9,20,null,null,15,7]
>
>   -10
>   / \
>  9  20
>    /  \
>   15   7
>
>Output: 42
>```

**Solution**

// TODO

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
  int maxPathSumI(TreeNode *p, int &ans) {
    if (p == nullptr) {
      return 0;
    } else {
      int L = max(0, maxPathSumI(p->left, ans));
      int R = max(0, maxPathSumI(p->right, ans));
      ans = max(ans, p->val + L + R);
      return p->val + max(L, R);
    }
  }
  
public:
  int maxPathSum(TreeNode* root) {
    int ans = numeric_limits<int>::min();
    maxPathSumI(root, ans);
    return ans;
  }
};
```

