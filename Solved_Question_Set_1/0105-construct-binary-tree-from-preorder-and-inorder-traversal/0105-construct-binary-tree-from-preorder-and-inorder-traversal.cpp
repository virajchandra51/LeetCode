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
    int pre = 0;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int st, int en)
    {
        if(st>en) return NULL;
        int val = preorder[pre++];
        int in = m[val];
        TreeNode* root = new TreeNode(val);
        root->left = helper(preorder,inorder,st,in-1);
        root->right = helper(preorder,inorder,in+1,en);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        return helper(preorder,inorder,0,inorder.size()-1);
    }
};