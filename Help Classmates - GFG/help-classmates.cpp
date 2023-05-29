//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty()==true)
            {
                st.push(i);
            }
            else
            {
                while(st.empty()==false && arr[i]<arr[st.top()])
                {
                    ans[st.top()]=arr[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty())
        {
            ans[st.top()]=-1;
            st.pop();
        }
        return ans;
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends