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
    void i(TreeNode* root){
        if(root==NULL){
            return;
        }
        v.push_back(root->val);
        i(root->left);
        i(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        i(root);
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=v[0])
                return false;
        }
        return true;
    }
};