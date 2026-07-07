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