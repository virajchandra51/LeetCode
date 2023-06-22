//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        vector<int> pp,tp;
        for(int i=0;i<n;i++)
        {
            if(arr[i]=='P')
            pp.push_back(i); else tp.push_back(i);
        }
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i<pp.size() && j<tp.size())
        {
            if(abs(pp[i]-tp[j])<=k)
            {
                ans++;
                i++;
                j++;
            }
            else if(pp[i]>tp[j]) j++;
            else i++;
        }
        return ans;
        // Code here 
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends