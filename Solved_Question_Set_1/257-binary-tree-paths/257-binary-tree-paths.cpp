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
    vector<vector<int>> v;
    void dfs(TreeNode* root, int value, vector<int> &a)
    {
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(a);
            return;
        }
        if(root->left)
        {
            value+=(root->left->val);
            a.push_back(root->left->val);
            dfs(root->left,value,a);
            value-=(root->left->val);
            a.pop_back();
        }
        if(root->right)
        {
            value+=(root->right->val);
            a.push_back(root->right->val);
            dfs(root->right,value,a);
            value-=(root->right->val);
            a.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> a;
        a.push_back(root->val);
        dfs(root,root->val,a);
        vector<string> s;
        for(auto it:v)
        {
            string w="";
            for(int i=0;i<it.size()-1;i++)
            {
                w+=(to_string(it[i]));
                w+="->";
            }
            w+=(to_string(it[it.size()-1]));
            s.push_back(w);
        }
        return s;
    }
};