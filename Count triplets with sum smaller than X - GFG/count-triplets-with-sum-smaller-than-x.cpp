//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    long long ans = 0;
	    sort(arr,arr+n);
	    vector<long long> v(n);
	    for(int i=0;i<n;i++) v[i] = arr[i];
	    for(int i=0;i<n-2;i++)
	    {
	        long long t = sum-v[i];
	        if(t<0)
	        continue;
	        int l = i+1;
	        int r = n-1;
	        while(l<r)
	        {
	            if(v[l]+v[r]<t)
	            {
	                ans+=(r-l);
	                l++;
	            }
	            else
	            r--;
	        }
	    }
	    return ans;
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
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends