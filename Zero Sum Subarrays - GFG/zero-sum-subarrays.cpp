//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        vector<long long int> pre(n);
        pre[0] = arr[0];
        for(int i=1;i<n;i++)
        pre[i] = pre[i-1]+arr[i];
        map<long long int,long long int> mp;
        for(auto it:pre)
        {
            mp[it]++;
        }
        long long int ans=0;
        for(auto it:mp)
        {
            ans+=it.second*(it.second-1)/2;
            if(it.first==0) ans+=it.second;
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
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends