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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        while(!q.empty())
        {
            long long size = q.size();
            long long mmin = q.front().second;
            long long first,last;
            for(int i=0;i<size;i++)
            {
                long long cur_id = q.front().second-mmin;
                TreeNode* n = q.front().first;
                q.pop();
                if(i==0) first = cur_id;
                if(i==(size-1)) last = cur_id;
                if(n->left) q.push({n->left,2*cur_id});
                if(n->right) q.push({n->right,2*cur_id+1});
            }
            ans=max(ans,last-first+1);
        }
        int a = (int)ans;
        return a;
    }
};