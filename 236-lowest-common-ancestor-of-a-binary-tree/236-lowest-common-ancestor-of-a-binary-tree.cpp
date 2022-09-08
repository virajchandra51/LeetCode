/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> p1,p2;
    void dfs(TreeNode* root, TreeNode* t, vector<TreeNode*> &p)
    {
        if(root==NULL)
            return;
        if(root==t)
        {
            p.push_back(root);
            p1=p;
            return;
        }
        if(root->left)
        {
            p.push_back(root);
            dfs(root->left,t,p);
            p.pop_back();
        }
        if(root->right)
        {
            p.push_back(root);
            dfs(root->right,t,p);
            p.pop_back();
        }
    }
    void dfs2(TreeNode* root, TreeNode* t, vector<TreeNode*> &q)
    {
        if(root==NULL)
            return;
        if(root==t)
        {
            q.push_back(root);
            p2=q;
            return;
        }
        if(root->left)
        {
            q.push_back(root);
            dfs2(root->left,t,q);
            q.pop_back();
        }
        if(root->right)
        {
            q.push_back(root);
            dfs2(root->right,t,q);
            q.pop_back();
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a,b;
        dfs(root,p,a);
        dfs2(root,q,b);
        int l=0,r=0;
        while(l<p1.size() && r<p2.size())
        {
            if(p1[l]!=p2[r])
                return p1[l-1];
            l++;r++;
        }
        if(l==p1.size())
            return p1[l-1];
        if(r==p2.size())
            return p2[r-1];
        
        return root;
    }
};