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
    map<int,int> m;
    int helper(TreeNode* root)
    {
        if(!root) return 0;
        int t = helper(root->left)+helper(root->right);
        root->val+=t;
        return root->val;
    }
    void helper2(TreeNode* root)
    {
        if(!root) return;
        m[root->val]++;
        helper2(root->left);
        helper2(root->right);
        return;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int sum = 0;
        helper(root);
        helper2(root);
        int f = -1;
        for(auto it:m) f=max(f,it.second);
        vector<int> a;
        for(auto it:m)
        {
            if(it.second==f)
                a.push_back(it.first);
        }
        return a;
    }
};