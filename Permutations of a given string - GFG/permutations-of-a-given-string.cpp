//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    sort(S.begin(),S.end());
		    int n = S.size();
		    vector<string> ans;
		    while(true)
		    {
		        ans.push_back(S);
		        int ind = n-1;
		        while(ind-1>=0 && S[ind]<=S[ind-1])
		        {
		            ind--;
		        }
		        if(ind-1<0)
		        break;
		        else
		        {
		            ind--;
		            int si = n-1;
		            while(S[si]<S[ind]) si--;
		            swap(S[si],S[ind]);
		            reverse(S.begin()+ind+1,S.end());
		            
		        }
		    }
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