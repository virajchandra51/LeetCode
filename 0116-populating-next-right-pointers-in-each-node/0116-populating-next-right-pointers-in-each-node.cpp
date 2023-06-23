/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* cur; Node* n;
        cur=root;
        while(cur)
        {
            n = cur;
            while(n)
            {
                if(n->left)
                n->left->next = n->right;
                if(n->next!=NULL && n->right) n->right->next = n->next->left;
                n = n->next;
            }
            cur = cur->left;
        }
        return root;
    }
};