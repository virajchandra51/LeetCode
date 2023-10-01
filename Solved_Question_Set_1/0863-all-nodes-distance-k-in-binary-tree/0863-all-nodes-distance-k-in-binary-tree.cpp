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
    void p(map<TreeNode*,TreeNode*>& m, TreeNode* root, TreeNode* par)
    {
        if(!root) return;
        if(par!=NULL)
        m[root]=par;
        p(m,root->left,root);
        p(m,root->right,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> m;
        p(m,root,NULL);
        queue<TreeNode*> q;
        q.push(target);
        int d = 0;
        vector<int> ans;
        set<TreeNode*> vis;
        vis.insert(target);
        while(!q.empty())
        {
            int kk = q.size();
            while(kk--)
            {
                auto it = q.front();
                q.pop();
                if(d==k) ans.push_back(it->val);
                if(m.find(it)!=m.end() && vis.find(m[it])==vis.end())
                {
                    vis.insert(m[it]);
                    q.push(m[it]);
                }
                if(it->left && vis.find(it->left)==vis.end())
                {
                    vis.insert(it->left);
                    q.push(it->left);
                }
                if(it->right && vis.find(it->right)==vis.end())
                {
                    vis.insert(it->right);
                    q.push(it->right);
                }
            }
            d++;
            if(d==(k+1)) break;
        }
        return ans;
    }
};