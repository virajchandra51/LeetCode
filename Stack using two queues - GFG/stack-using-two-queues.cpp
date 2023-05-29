//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
    // Your Code
    q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(q1.size()==0) return -1;
    while(q1.size()>1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int a = q1.front();
    q1.pop();
    q1=q2;
    while(!q2.empty()) q2.pop();
    return a;
        // Your Code       
}
