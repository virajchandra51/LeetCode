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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root==NULL)
            return {};
        q.push(root);
        while(!q.empty())
        {
            queue<TreeNode*> temp; 
            vector<int> a;
            while(!q.empty())
            {
                TreeNode* n = q.front();
                q.pop();
                a.push_back(n->val);
                if(n->left)
                temp.push(n->left);
                if(n->right)
                temp.push(n->right);
            }
            v.push_back(a);
            q=temp;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};