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
    int ans=-1; int f=0;
    void in(TreeNode* root, int &k)
    {
        if(root==NULL)
            return; 
        in(root->left,k);
        k--;
        cout<<k<<endl;
        if(k==0)
        {
            if(f==0)
            {
                ans=root->val;
                f=1;
            }
        }
        in(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        in(root,k);
        return ans;
    }
};