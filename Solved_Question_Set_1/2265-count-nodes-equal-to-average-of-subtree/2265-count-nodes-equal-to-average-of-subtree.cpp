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
    int c = 0;
    pair<int,int> helper(TreeNode* root)
    {
        if(!root) return {0,0};
        int t = root->val;
        int currC = 1;
        auto t1 = helper(root->left);
        auto t2 = helper(root->right);
        t+=t1.first;
        t+=t2.first;
        currC+=t1.second;
        currC+=t2.second;
        if(t/currC==(root->val)) c++;
        root->val = t;
        return {t,currC};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return c;
    }
};