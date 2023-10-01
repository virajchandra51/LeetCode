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
    int maxDepth(Node* root) {
        queue<Node*> q;
        if(root==NULL)
            return 0;
        q.push(root);
        int d=0;
        while(!q.empty())
        {
            queue<Node*> t;
            while(!q.empty())
            {
                Node* n = q.front();
                q.pop();
                for(auto it:n->children)
                {
                    if(it!=NULL)
                        t.push(it);
                }
            }
            q=t;
            d++;
        }
        return d;
    }
};