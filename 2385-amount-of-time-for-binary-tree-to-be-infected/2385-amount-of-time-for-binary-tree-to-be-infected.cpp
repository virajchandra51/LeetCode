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
    vector<int> adj[100001];
    
    void addEdge(TreeNode* root){
        if(root==NULL)
            return;
        if(root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            addEdge(root->left);
        }
        if(root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            addEdge(root->right);
        }
    }
    int vis[100005];
    int solve(int v){
       vis[v]=1;
       int ans=0;
       for(auto child: adj[v]){
           if(vis[child]==0){
               ans= max(ans,solve(child));
           }
       }
     return ans+1;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root->left==NULL && root->right==NULL)
            return 0;
        addEdge(root);
        
        return solve(start)-1;
    }
};