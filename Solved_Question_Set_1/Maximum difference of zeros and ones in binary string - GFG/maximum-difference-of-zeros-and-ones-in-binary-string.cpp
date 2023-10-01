//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int ans = 0;
	    int s = 0;
	    for(auto it:S)
	    {
	        if(it=='1')
	        s--;
	        else 
	        s++;
	        if(s<0) s=0;
	        ans=max(ans,s);
	    }
	    return ans==0?-1:ans;
	    // Your code goes here
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends