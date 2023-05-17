//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	long long getCount(int n)
	{
	    vector<long long> v(10,1);
	    long long s = 10;
	    if(n==1) return s;
	    for(int i=2;i<=n;i++)
	    {
	        vector<long long> vv = v;
	        vv[0]+=(v[8]);
	        vv[1]+=(v[2]+v[4]);
	        vv[2]+=(v[1]+v[3]+v[5]);
	        vv[3]+=(v[2]+v[6]);
	        vv[4]+=(v[1]+v[5]+v[7]);
	        vv[5]+=(v[2]+v[4]+v[6]+v[8]);
	        vv[6]+=(v[5]+v[3]+v[9]);
	        vv[7]+=(v[4]+v[8]);
	        vv[8]+=(v[7]+v[5]+v[9]+v[0]);
	        vv[9]+=(v[8]+v[6]);
	        s = 0;
	        for(auto it:vv)
	        s+=it;
	        v=vv;
	    }
	    return s;
		// Your code goes here
	}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends