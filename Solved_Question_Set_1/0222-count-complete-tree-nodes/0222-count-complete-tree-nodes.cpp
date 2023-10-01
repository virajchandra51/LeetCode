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
    int countNodes(TreeNode* root) {
        int c=0;
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            queue<TreeNode*> t;
            while(!q.empty())
            {
                TreeNode* n = q.front();
                q.pop();
                c++;
                if(n->left)
                    t.push(n->left);
                
                if(n->right)
                    t.push(n->right);
                
            }
            q=t;
                
        }
        return c;
    }
};