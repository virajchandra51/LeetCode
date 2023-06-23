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
        TreeNode* curr=root;
        while(curr)
        {
            if(curr->left)
            {
                TreeNode* pre = curr->left;
                while(pre->right) pre=pre->right;
                pre->right=curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr=curr->right;
        }
        return;
        // this is like a threading, im trying to connect the last guy in the preorder of the left substree to the first guy in the preorder of right tree
        // so i take pre to be curr->lfet and make it the rightest it can be and then i connect it to the right of curr which is the first node int the preoder of the right subtree now i jump curr right to curr left and curr left to NULL
    }
};