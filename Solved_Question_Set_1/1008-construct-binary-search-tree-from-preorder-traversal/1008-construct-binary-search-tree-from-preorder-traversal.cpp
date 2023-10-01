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
    TreeNode* helper(vector<int>& pre, int &i, int mi, int mx, int n)
    {
        if(i>=n) return NULL;
        TreeNode* r = NULL;
        if(pre[i]>mi && pre[i]<mx)
        {
            r = new TreeNode(pre[i]);
            i++;
            if(i<n)
                r->left = helper(pre,i,mi,r->val,n);
            if(i<n)
                r->right = helper(pre,i,r->val,mx,n);
        }
        return r;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return helper(preorder,i,INT_MIN,INT_MAX,preorder.size());
    }
};