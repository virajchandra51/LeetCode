//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here  
        sort(arr,arr+N);
        reverse(arr,arr+N);
        if(N==1) return 0;
        int i = 0;
        int j = 1;
        int sum = 0;
        while(j<N)
        {
            if(arr[i]-arr[j]<K)
            {
                sum+=arr[i];
                sum+=arr[j];
                i=j+1;
                j=i+1;
            }
            else
            {
                i++;
                j++;
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends