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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root); 
        while(!q.empty())
        {
            queue<TreeNode*> temp; long long sum=0; long long count=0;
            while(!q.empty())
            {
                TreeNode* n  = q.front();
                sum+= (n->val);
                q.pop();
                count++;
                if(n->left!=NULL)
                temp.push(n->left);
                if(n->right!=NULL)
                temp.push(n->right);
                
            }
            q=temp;
            res.push_back(sum*1.0/count);
        }
        return res;
    }
};