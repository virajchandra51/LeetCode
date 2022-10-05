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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* ans = new TreeNode(val,root,NULL);
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            depth--;
            if(depth==1)
                break;
            queue<TreeNode*> temp;
            while(!q.empty())
            {
                TreeNode* n = q.front();
                q.pop();
                if(n->left)
                    temp.push(n->left);
                if(n->right)
                    temp.push(n->right);
            }
            q=temp;
        }
        while(!q.empty())
        {
                TreeNode* n = q.front();
                q.pop();
                TreeNode* l = n->left;
                n->left = new TreeNode(val,l,NULL);
                TreeNode* r = n->right;
                n->right = new TreeNode(val,NULL,r);
                
        }
        return root;
    }
};