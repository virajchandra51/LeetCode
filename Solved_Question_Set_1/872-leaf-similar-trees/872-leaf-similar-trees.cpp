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
    vector<int> a,b;
    void dfs1(TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            a.push_back(root->val);
        dfs1(root->left);
        dfs1(root->right);
    }
    void dfs2(TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            b.push_back(root->val);
        dfs2(root->left);
        dfs2(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs1(root1);
        dfs2(root2);
        return a==b;
    }
};