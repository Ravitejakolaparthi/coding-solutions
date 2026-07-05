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
            int lh,rh;
            if(lh - rh >= -1 && lh - rh <= 1)
            return false;
            else
            {
             lh = isBalanced(root -> left)+1;
             rh = isBalanced(root -> right)+1;
            }
            return true;
        }
        
    }
};