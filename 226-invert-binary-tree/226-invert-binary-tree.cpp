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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL)
            return root;
        q.push(root);
        while(!q.empty())
        {
            queue<TreeNode*> temp;
            while(!q.empty())
            {
                TreeNode* n = q.front();
                q.pop();
                if(n->left)
                temp.push(n->left);
                if(n->right)
                temp.push(n->right);
                TreeNode* t = n->left;
                n->left = n->right;
                n->right = t;
            }
            q=temp;
        }
        return root;
    }
};