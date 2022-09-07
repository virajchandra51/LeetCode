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
    vector<int> v;
    void in(TreeNode* root)
    {
        if(root==NULL)
            return;
        in(root->left);
        v.push_back(root->val);
        in(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        in(root);
        TreeNode* ans = new TreeNode(0);
        TreeNode* c = ans;
        for(auto i:v)
        {
            ans->left = NULL;
            ans->right = new TreeNode(i);
            ans = ans->right;
        }
        return c->right;
    }
};