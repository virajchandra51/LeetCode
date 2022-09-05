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
    
    bool isS(vector<int> &v)
    {
        for(int i=0;i<v.size()/2;i++)
        {
            if(v[i]!=v[v.size()-1-i])
                return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            queue<TreeNode*> temp;
            vector<int> a;
            while(!q.empty())
            {
                TreeNode* n = q.front();
                q.pop();
                if(n==NULL)
                    a.push_back(101);
                else
                {
                    a.push_back(n->val);
                    temp.push(n->left);
                    temp.push(n->right);
                }
            }
            q=temp;
            if(isS(a)==false)
                return false;
        }
        return true;
    }
};