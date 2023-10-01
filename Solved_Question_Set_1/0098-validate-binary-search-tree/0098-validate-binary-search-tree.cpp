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
    bool helper(TreeNode* root, long long mr, long long mxr)
    {
        if(root==NULL) return true;
        if(root->val<mr || root->val>mxr) return false;
        long long v = root->val;
        return helper(root->left,mr,v-1)&&helper(root->right,v+1,mxr);
    }
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
        long long mr = INT_MIN;
        long long mxr = INT_MAX;
        return helper(root,mr,mxr);
    }
};