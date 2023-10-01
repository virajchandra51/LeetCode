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
    long long sum = 0;
    void DFS(TreeNode* root, int value)
    {
        if(root->left==NULL && root->right==NULL)
        {
            sum+=(value);
            return;
        }
        if(root->left!=NULL)
        {
            value=value<<1;
            DFS(root->left, value + root->left->val);
            value=value>>1;
        }
        if(root->right!=NULL)
        {
            value=value<<1;
            DFS(root->right, value + root->right->val);
            value=value>>1;
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        DFS(root,root->val);
        return sum;
    }
};