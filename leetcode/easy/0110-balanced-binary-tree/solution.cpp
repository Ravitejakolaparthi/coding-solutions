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
    bool isBalanced(TreeNode* root) {
        int h = 0;
        if(root == nullptr)
        return 0;
        else
        {
            
            
            if(h<= -1 && h>= 1)
            return false;
            else
            {
            h = max(isBalanced(root->left),isBalanced(root->right))+1;
            return h;
            }
        }
    }
};