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
    int goodNodes(TreeNode* root,int mx = INT_MIN) {
        // if the root is null, we return 0
        if (!root) return 0;
        // then we can break it into 3 parts
        // the first part is the current node
        // if the current node value is greater than the maximum value so far
        // that means the current node is a good node
        // hence we add 1, else add 0
        return (mx <= root->val ? 1 : 0) + 
                // the second part is the result of the left sub-tree
                // we traverse it with the updated maximum value at the current point
                // we don't need to check if root->left is null or not here
                // as we cover the null case in the first line
                goodNodes(root->left, max(root->val, mx)) + 
                // the last part is the result of the right sub-tree
                // we traverse it with the updated maximum value at the current point
                // we don't need to check if root->right is null or not here
                // as we cover the null case in the first line
                goodNodes(root->right, max(root->val, mx));
    }
};