//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int M = 1000000007;
		int CountWays(string s){
		    // Code here
		    int n = s.size();
		    vector<int> dp(n+1,0);
		    dp[0]=1;
		    dp[1] = s[0]=='0'?0:1;
		    // 0 1 2 
		    for(int i=2;i<=n;i++)
		    {
		        int f = stoi(s.substr(i-1,1));
            int ss = stoi(s.substr(i-2,2));
            if(f>=1 && f<=9)
                dp[i]=(dp[i]%M+dp[i-1]%M)%M;
            if(ss>=10 && ss<=26)
                dp[i]=(dp[i]%M+dp[i-2]%M)%M;
		    }
		    return dp[n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends