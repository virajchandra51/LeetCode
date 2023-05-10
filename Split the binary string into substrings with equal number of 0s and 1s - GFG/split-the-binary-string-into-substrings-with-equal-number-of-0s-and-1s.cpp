//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int c=0;
        int cc=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='0') c++;
            else c--;
            if(c==0) cc++;
            // if(c<0) c=0;
        }
        if(c!=0) return -1;
        return cc;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends