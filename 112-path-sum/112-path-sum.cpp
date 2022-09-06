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
    int f=0;
    void DFS(TreeNode* root, int value, int target)
    {
        if(root->left==NULL && root->right==NULL)
        {
            if(value==target)
            {
                f=1;   
            }
            return;
        }
        if(root->left)
        {
            value+=(root->left->val);
            DFS(root->left,value,target);
            value-=(root->left->val);
        }
        if(root->right)
        {
            value+=(root->right->val);
            DFS(root->right,value,target);
            value-=(root->right->val);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        DFS(root,root->val,targetSum);
        if(f)
            return true;
        return false;
    }
};