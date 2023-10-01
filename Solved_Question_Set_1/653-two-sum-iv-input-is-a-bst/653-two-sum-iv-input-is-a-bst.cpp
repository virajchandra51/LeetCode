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
    map<int,int> mp;
    void dfs(TreeNode* root)
    {
        if(root==NULL)
            return;
        mp[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        for(auto it:mp)
        {
            if((it.first*2==k && it.second>1) || (mp.find((k-it.first))!=mp.end() && (k-it.first)!=it.first))
                return true;
        }
        return false;
    }
};