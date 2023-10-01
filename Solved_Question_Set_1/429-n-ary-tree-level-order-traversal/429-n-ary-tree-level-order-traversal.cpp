/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if(root==NULL)
            return {};
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            queue<Node*> temp;
            vector<int> a;
            while(!q.empty())
            {
                Node* num = q.front();
                q.pop();
                a.push_back(num->val);
                for(auto it: num->children)
                    temp.push(it);
            }
            q=temp;
            v.push_back(a);
        }
        return v;
    }
};