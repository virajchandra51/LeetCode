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
    long long int smin = LLONG_MAX;

void dfs(TreeNode *root , int rootVal)
{
    if(root == NULL)
        return;
    
    if(root->val != rootVal && (smin > root->val))
        smin = root->val;
    
    if(smin <= root->val )
        return ;
    
    dfs(root->left , rootVal);
    dfs(root->right , rootVal);
}


int findSecondMinimumValue(TreeNode* root) {
    
    if(root == NULL)
        return -1;
    
    dfs(root , root->val );
    return smin == LLONG_MAX ? -1 : smin;
}
};