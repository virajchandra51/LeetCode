//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    // apply lca;
    vector<Node*> a,b;
    void d(Node* root, int t, vector<Node*> &v)
    {
        if(root==NULL) return;
        if(root->data==t)
        {
            v.push_back(root);
            a=v;
            v.pop_back();
            return;
        }
        v.push_back(root);
        d(root->left,t,v);
        d(root->right,t,v);
        v.pop_back();
    }
    void dd(Node* root, int t, vector<Node*> &v)
    {
        if(root==NULL) return;
        if(root->data==t)
        {
            v.push_back(root);
            b=v;
            v.pop_back();
            return;
        }
        v.push_back(root);
        dd(root->left,t,v);
        dd(root->right,t,v);
        v.pop_back();
    }
    Node* lca()
    {
        Node* ans;
        int i=0;int j=0;
        while(i<a.size() && j<b.size())
        {
            if(a[i]==b[j])
            ans=a[i];
            i++;
            j++;
        }
        return ans;
    }
    int h(Node* root, int t)
    {
        queue<Node*> q;
        int d=0;
        q.push(root);
        while(!q.empty())
        {
            int k = q.size();
            while(k--)
            {
                Node* n= q.front();
                if(n->data==t) return d;
                q.pop();
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            d++;
        }
        return -1;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        vector<Node*> a1,b1;
        d(root,a,a1);
        dd(root,b,b1);
        Node* l = lca();
        int h1 = h(l,a);
        int h2 = h(l,b);
        return h1+h2;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends