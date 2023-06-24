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
class Node{
    public:
        int sum;
        bool isBST;
        int l;
        int r;
        Node()
        {
            sum=0;
            isBST=true;
            l=INT_MIN;
            r=INT_MAX;
        }
};
class Solution {
public:
    int ans = 0;
    Node* helper(TreeNode* root)
    {
        if(root==NULL)
        {
            Node* r = new Node();
            return r;
        }
        Node* l = helper(root->left);
        Node* r = helper(root->right);
        Node* curr = new Node();
        curr->isBST = l->isBST && r->isBST && root->val>l->l && root->val<r->r;
        curr->sum = root->val;
        curr->sum+=(l->sum+r->sum);
        if(curr->isBST)
        {
            ans=max(ans,curr->sum);
        }
        else
        {
            curr->sum = 0;
        }
        curr->r = min(root->val,l->r);
        curr->l = max(root->val,r->l);
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};