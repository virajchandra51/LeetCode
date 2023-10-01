//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int n = nums.size();
        int x = nums[0];
        for(int i=1;i<n;i++) x^=nums[i];
        int xx = x;
        int j = 0;
        while(xx)
        {
            if(xx&1) break;
            xx>>=1;
            j++;
        }
        j = (1<<j);
        int s1=0,s2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]&j)
            s1^=nums[i];
            else
            s2^=nums[i];
        }
        if(s1>s2)
        return {s2,s1};
        return {s1,s2};
        // Code here.
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends