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
    TreeNode* helper(TreeNode* root, int a, int b)
    {
        if(!root) return NULL;
        if(root->val==a || root->val==b) return root;
        TreeNode* left = helper(root->left, a,b);
        TreeNode* right = helper(root->right,a,b);
        if(left && right)
            return root;
        if(left) return left;
        return right;
    }
    bool findPath(TreeNode* root, int val, string &path){
        if(root->val==val){
            return true;
        }
        if(root->left && findPath(root->left,val,path)){
            path.push_back('L');
        }
        else if(root->right && findPath(root->right,val,path)){
             path.push_back('R');
        }
        return !path.empty();
    }
    string getDirections(TreeNode* root, int a, int b) {
        TreeNode* lca = helper(root,a,b);
        string a1,b1;
        findPath(lca,a,a1);
        findPath(lca,b,b1);
        return string(a1.size(),'U')+string(rbegin(b1),rend(b1));
    }
};