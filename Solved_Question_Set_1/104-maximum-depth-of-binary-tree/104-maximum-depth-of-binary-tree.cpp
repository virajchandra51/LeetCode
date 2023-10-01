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
    int maxDepth(TreeNode* root) {
        int d=1;
        queue<TreeNode*> q;
        if(root==NULL)
            return 0;
        q.push(root);
        while(!q.empty())
        {
            queue<TreeNode*> t;
            while(!q.empty())
            {
                TreeNode* n = q.front();
                q.pop();
                if(n->left)
                    t.push(n->left);
                if(n->right)
                    t.push(n->right);
            }
            q=t;
            d++;
        }
        return d-1;
    }
};