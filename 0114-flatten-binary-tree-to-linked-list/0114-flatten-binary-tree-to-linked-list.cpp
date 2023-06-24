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
    void flatten(TreeNode* root) {
        TreeNode* pre = root;
        TreeNode* curr;
        while(pre)
        {
            if(pre->left)
            {
                curr = pre->left;
                while(curr->right) curr=curr->right;
                curr->right = pre->right;
                pre->right = pre->left;
                pre->left = NULL;
                pre = pre->right;
            }
            else pre = pre->right;
        }
        return;
    }
};