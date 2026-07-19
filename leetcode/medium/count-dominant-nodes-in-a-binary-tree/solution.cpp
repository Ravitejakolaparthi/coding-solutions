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
    TreeNode* solve(TreeNode*root,int &c)
    {
        if(root == nullptr) return nullptr;
        if(root->left  == nullptr && root -> right == nullptr)
        {
            c++;
            return root;
        }
        else
        {
            TreeNode * t1 = solve(root->left,c);
            TreeNode * t2 = solve(root->right,c);
            if (t1 != nullptr && t2 != nullptr && root->val >= t1->val && root->val >= t2->val)
                c++;
            if (t1 != nullptr && t2 == nullptr && root->val >= t1->val)
                c++;
            if (t1 == nullptr && t2 != nullptr && root->val >= t2->val)
                c++;

            TreeNode* maxNode = root;
            if (t1 != nullptr && t1->val > maxNode->val) 
                maxNode = t1;
            if (t2 != nullptr && t2->val > maxNode->val) 
                maxNode = t2;
            return maxNode;
        }
        
    }
    int countDominantNodes(TreeNode* root) {
            int c = 0;
            solve(root,c);
        return c;
    }
};