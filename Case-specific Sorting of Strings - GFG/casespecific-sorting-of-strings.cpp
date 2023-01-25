//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string a="",b="";
        for(auto it:str)
        {
            if(it>='a' && it<='z')
            a+=it;
            else b+=it;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int p1=0,p2=0;
        string ans="";
        for(auto it:str)
        {
            if(it>='a' && it<='z')
            {
                ans+=a[p1++];
            }
            else
            ans+=b[p2++];
        }
        return ans;
        // your code here
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
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends