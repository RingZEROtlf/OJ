# 99. Recover Binary Search Tree

>Two elements of a binary search tree (BST) are swapped by mistake.
>
>Recover the tree without changing its structure.
>
>**Example 1:**
>
>```
>Input: [1,3,null,null,2]
>
>   1
>  /
> 3
>  \
>   2
>
>Output: [3,1,null,null,2]
>
>   3
>  /
> 1
>  \
>   2
>```
>
>**Example 2:**
>
>```
>Input: [3,1,4,null,null,2]
>
>  3
> / \
>1   4
>   /
>  2
>
>Output: [2,1,4,null,null,3]
>
>  2
> / \
>1   4
>   /
>  3
>```
>
>**Follow up:**
>
>- A solution using O(*n*) space is pretty straight forward.
>- Could you devise a constant space solution?

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
public:
  void recoverTree(TreeNode* root) {
    TreeNode *first = nullptr, *second = nullptr;
    TreeNode *curr = root, *prev = nullptr, *father = nullptr;
    while (curr != nullptr) {
      if (curr->left == nullptr) {
        if (father != nullptr && father->val > curr->val) {
          if (first == nullptr) {
            first = father;
          }
          second = curr;
        }
        father = curr;
        curr = curr->right;
      } else {
        prev = curr->left;
        while (prev->right != nullptr && prev->right != curr) {
          prev = prev->right;
        }
        if (prev->right == nullptr) {
          prev->right = curr;
          curr = curr->left;
        } else {
          prev->right = nullptr;
          if (father->val > curr->val) {
            if (first == nullptr) {
              first = father;
            }
            second = curr;
          }
          father = curr;
          curr = curr->right;
        }
      }
    }
    swap(first->val, second->val);
  }
};
```

