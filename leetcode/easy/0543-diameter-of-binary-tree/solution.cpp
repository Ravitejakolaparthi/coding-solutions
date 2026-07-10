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
     
     
     return Traverse(root,0); 
    }
};