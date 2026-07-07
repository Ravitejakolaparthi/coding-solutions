# Invert Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `root` of a binary tree, invert the tree, and return  *its root*.

 

 **Example 1:** 

```
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

```

 **Example 2:** 

```
Input: root = [2,1,3]
Output: [2,3,1]

```

 **Example 3:** 

```
Input: root = []
Output: []

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 12.3 MB (beats 87.74%)  
**Submitted:** 2026-07-07T08:54:33.670Z  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
       if(root == nullptr)
       return root;
       else{
        TreeNode*le = nullptr;
        TreeNode*re = nullptr;
        le = invertTree(root->left);
        re = invertTree(root->right);

        root -> left = re;
        root -> right = le;

       }
       return root;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/invert-binary-tree/)