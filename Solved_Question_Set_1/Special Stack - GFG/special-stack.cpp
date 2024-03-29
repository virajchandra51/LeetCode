//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends

int mi;
void push(stack<int>& s, int a){
	// Your code goes here
	if(s.size()==0)
	{
	    mi=a;
	    s.push(a);
	}
	else
	{
	    int x = a;
	    if(a<mi)
	    {
	        x = 2*a-mi;
	        mi = a;
	    }
	    s.push(x);
	}
	return;
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	if(s.size()==n) return true;
	return false;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	if(s.size()==0) return true;
	return false;
}

int pop(stack<int>& s){
	// Your code goes here
	int v = s.top();
	if(v>=mi) s.pop();
	else
	{
	    int y = 2*mi-v;
	    s.pop();
	    mi = y;
	}
}

int getMin(stack<int>& s){
	// Your code goes here
	return mi;
}