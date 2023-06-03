//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	string FirstNonRepeating(string a){
	    // Code here
	    string ans = ""; ans+=a[0];
	    int n = a.size();
	    vector<pair<int,int>> v;
	    v.push_back({a[0],1});
	    for(int i=1;i<n;i++)
	    {
	        int ff=0;
	        for(auto &it:v)
	        {
	            if(it.first==a[i])
	            {
	                ff=1;
	                it.second++;
	                break;
	            }
	        }
	        if(ff==0)
	        v.push_back({a[i],1});
	        int f=0;
	        for(auto it:v)
	        {
	            if(it.second==1)
	            {
	                f=1;
	                ans+=it.first;
	                break;
	            }
	        }
	        if(f==0) ans+='#';
	       // cout<<endl;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends