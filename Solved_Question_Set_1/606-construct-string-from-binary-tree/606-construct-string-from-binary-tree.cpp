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
    string s;
    void pre(TreeNode* root)
    {
        if(root==NULL)
            return;
        s+=(to_string(root->val));
        if(root->left==NULL && root->right)
            s+="()";
        if(root->left)
        {
            s+='(';
            pre(root->left);
            s+=')';
        }
        if(root->right)
        {
            s+='(';
            pre(root->right);
            s+=')';
        }
    }
    string tree2str(TreeNode* root) {
        pre(root);
        return s;
    }
};