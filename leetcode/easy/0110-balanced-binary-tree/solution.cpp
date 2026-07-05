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
    int check(TreeNode* root)
    {
        int flag = 0;
        int lh = 0;
        int rh = 0;
        if(root == nullptr)
        return 0;
        else
        {
            lh = check(root -> left) +1;
            rh = check(root -> right) +1;
            if(lh-rh <= -1 && lh -rh >=1)
            {
                flag = 1;
            }
        }
        if(flag == 1)
        return 0;
        else
        return 1;

    }
    bool isBalanced(TreeNode* root) {
      return check(root);
    }
};