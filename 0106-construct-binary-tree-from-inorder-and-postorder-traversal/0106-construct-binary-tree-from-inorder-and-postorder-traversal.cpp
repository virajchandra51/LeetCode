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
    map<int,int> m;
    int pos;
    TreeNode* helper(vector<int>& po, vector<int>& inorder, int st, int en)
    {
        if(st>en) return NULL;
        TreeNode* root = new TreeNode(po[pos]);
        int in = m[po[pos--]];
        root->right = helper(po,inorder,in+1,en);
        root->left = helper(po,inorder,st,in-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po){
        pos = po.size()-1;
        for(int i=0;i<in.size();i++) m[in[i]]=i;
        return helper(po,in,0,in.size()-1);
    }
};