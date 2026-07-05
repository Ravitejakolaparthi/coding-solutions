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
        if(root == nullptr)
        return 0;
        else
        {
            int h = isBalanced(root->left) - isBalanced(root->right);
            cout << h <<endl;
            if(h<= -1 && h>= 1)
            return false;
            else
            return max(isBalanced(root->left),isBalanced(root->right))+1;
            
        }
    }
};