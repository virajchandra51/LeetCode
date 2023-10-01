//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    vector<int> a;
    int l = 0;
    int r = n-1;
    int f=1;
    while(l<=r)
    {
        if(f)
        {
            a.push_back(arr[l]);
            l++;
        }
        else
        {
            a.push_back(arr[r]);
            r--;
        }
        f=!f;
    }
    long long int ans = 0;
    for(int i=0;i<a.size()-1;i++)
    ans+=abs(a[i]-a[i+1]);
    ans+=abs(a[a.size()-1]-a[0]);
    return ans;
}