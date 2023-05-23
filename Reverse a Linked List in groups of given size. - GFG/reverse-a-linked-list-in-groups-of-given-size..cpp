//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node* reverse(struct node* begin, struct node* end)
    {
        struct node* curr = begin->next;
        struct node* prev = begin;
        struct node* next; struct node* first;
        first = curr;
        while(curr!=end)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        begin->next = prev;
        first->next = curr;
        return first;
        
    }
    struct node *reverse (struct node *h, int k)
    { 
        if(k==1) return h;
        if(h->next==NULL) return h;
        struct node* begin = new node(-1);
        begin->next = h;
        struct node* ans = begin;
        int i=0;
        while(h!=NULL)
        {
            i++;
            if(i%k==0)
            {
                begin = reverse(begin,h->next);
                h=begin->next;
            }
            else
            {
                h=h->next;
            }
        }
        if(i%k!=0)
        reverse(begin,h);
        return ans->next;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends