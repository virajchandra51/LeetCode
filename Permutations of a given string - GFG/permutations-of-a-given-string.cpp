//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    sort(s.begin(),s.end());
		    vector<string> ans;
		    int n = s.size();
		    while(true)
		    {
		        ans.push_back(s);
		        int ind = n-1;
		        while(ind-1>=0 && s[ind-1]>=s[ind])
		        {
		            ind--;
		        }
		        if(ind==0) break;
		        ind--;
		        int i = n-1;
		        while(s[ind]>=s[i])
		        i--;
		      //  cout<<ind<<" "<<i<<endl;
		        char ch = s[ind];
		        s[ind] = s[i];
		        s[i] = ch;
		        reverse(s.begin()+ind+1,s.end());
		      //  break;
		    }
		  //  cout<<s<<endl;
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends