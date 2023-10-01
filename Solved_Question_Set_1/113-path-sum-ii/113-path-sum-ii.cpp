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
    vector<vector<int>> v;
    void dfs(TreeNode* root, int value, int target, vector<int> &a)
    {
        if(root->left==NULL && root->right==NULL)
        {
            if(value==target)
                v.push_back(a);
            return;
        }
        if(root->left)
        {
            value+=(root->left->val);
            a.push_back(root->left->val);
            dfs(root->left,value,target,a);
            value-=(root->left->val);
            a.pop_back();
        }
        if(root->right)
        {
            value+=(root->right->val);
            a.push_back(root->right->val);
            dfs(root->right,value,target,a);
            value-=(root->right->val);
            a.pop_back();
        }
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return {};
        vector<int>a;
        a.push_back(root->val);
        dfs(root,root->val,targetSum,a);
        return v;
    }
};