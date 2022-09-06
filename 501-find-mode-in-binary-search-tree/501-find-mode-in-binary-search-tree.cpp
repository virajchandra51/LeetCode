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
    void pre(TreeNode* root)
    {
        if(root==NULL)
            return;
        mp[root->val]++;
        pre(root->left);
        pre(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        pre(root);
        int f=-1;
        for(auto it:mp)
            f=max(f,it.second);
        vector<int> a;
        for(auto it:mp)
        {
            if(it.second==f)
                a.push_back(it.first);
        }
        return a;
    }
};