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
    bool contains(TreeNode* root){
        if(root==NULL) return false;
        bool Left = contains(root->left);
        bool Right = contains(root->right);
        if(!Left) root->left = NULL;
        if(!Right) root->right = NULL;
        return root->val==1 || Left || Right;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        return contains(root)?root:NULL;
    }
};