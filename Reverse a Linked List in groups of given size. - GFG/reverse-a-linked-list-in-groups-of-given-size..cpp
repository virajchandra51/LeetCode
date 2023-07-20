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
    struct node *rev(struct node *begin, struct node *end)
    {
        struct node* curr = begin->next;
        struct node* copy = curr;
        begin->next = NULL;
        struct node* prev = begin;
        struct node* next = NULL;
        while(curr!=end)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        begin->next = prev;
        copy->next = curr;
        return copy;
    }
    struct node *reverse (struct node *head, int k)
    { 
        struct node* begin = new node(-1);
        begin->next = head;
        struct node *ans = begin;
        int c = 0;
        while(head)
        {
            c++;
            head=head->next;
            if(c%k==0)
            {
                begin = rev(begin,head);
            }
        }
        if(c%k!=0)
        begin = rev(begin,head);
        return ans->next;
        // Complete this method
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