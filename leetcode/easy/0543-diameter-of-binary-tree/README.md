# Diameter of Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `root` of a binary tree, return  *the length of the  **diameter**  of the tree*.

The  **diameter**  of a binary tree is the  **length**  of the longest path between any two nodes in a tree. This path may or may not pass through the `root`.

The  **length**  of a path between two nodes is represented by the number of edges between them.

 

 **Example 1:** 

```
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

```

 **Example 2:** 

```
Input: root = [1,2]
Output: 1

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [1, 104].
- -100 <= Node.val <= 100

## Solution

**Language:** C++  
**Runtime:** 339 ms (beats 5.09%)  
**Memory:** 23.7 MB (beats 42.44%)  
**Submitted:** 2026-07-10T09:48:07.069Z  

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
    int depthofleft(TreeNode*root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        else
        {
            return max(depthofleft(root->left),depthofleft(root->right))+1;
        }
    }
     int depthofright(TreeNode*root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        else
        {
            return max(depthofright(root->left),depthofright(root->right))+1;
        }
    }
    int Traverse(TreeNode*root,int m){
        if(root != nullptr)
        {       m = Traverse(root -> left,m);
                int a =   depthofleft(root->left);
                int b =   depthofright(root->right);
                m = max(m,a + b);
                m = Traverse(root->right,m);
        }
        return m;
    }
    int diameterOfBinaryTree(TreeNode* root) {
    int c = 0; 
     c = Traverse(root,0); 
     return c;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/diameter-of-binary-tree/)