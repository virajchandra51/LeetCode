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
    int minDepth(TreeNode* root) {
        int d=0;
        queue<TreeNode*> q;
        if(root==NULL)
            return 0;
        q.push(root);
        while(!q.empty())
        {
            queue<TreeNode*> temp;
            while(!q.empty())
            {
                TreeNode* n = q.front();
                q.pop();
                if(n->left==NULL && n->right==NULL)
                    return d+1;
                if(n->left)
                    temp.push(n->left);
                if(n->right)
                    temp.push(n->right);
            }
            d++;
            q=temp;
        }
        return d+1;
    }
};