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
    int ans=0;
    void dfs2(TreeNode* root, long long t)
    {
        if(root==NULL)
            return;
        if(root->val==t)
            ans++;
        dfs2(root->left,t-root->val);
        dfs2(root->right,t-root->val);
    }
    void dfs(TreeNode* root, long long t)
    {
        if(root==NULL)
            return;
        dfs2(root,t);
        dfs(root->left,t);
        dfs(root->right,t);
    }
    int pathSum(TreeNode* root, int t) {
        if(root==NULL)
            return 0;
        dfs(root,t);
        return ans;
    }
};