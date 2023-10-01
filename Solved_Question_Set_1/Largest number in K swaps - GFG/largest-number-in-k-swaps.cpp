//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string ans;
    void helper(string &str, int k, int st, int n)
    {
        if(str>ans)
            ans=str;
        if(k==0 || st>=n)
        {
            if(str>ans)
            ans=str;
            return;
        }
        int mi = INT_MIN;
        for(int i=st+1;i<n;i++)
        mi = max(mi,str[i]-'0');
        // cout<<mi<<endl;
        vector<int> ind;
        for(int i=st+1;i<n;i++)
        {
            if((str[i]-'0')==mi)
            ind.push_back(i);
        }
        for(auto it:ind)
        {
            if(st!=it && (str[it]-'0')>(str[st]-'0'))
            {
                char ch=str[it];
                str[it]=str[st];
                str[st]=ch;
                // swap(str[it],&str[st]);
                helper(str,k-1,st+1,n);
                ch=str[it];
                str[it]=str[st];
                str[st]=ch;
                // swap(str[it],str[st]);
            }
            else
            {
                helper(str,k,st+1,n);
            }
        }
        return;
    }
    string findMaximumNum(string str, int k)
    {
        ans=str;
        int n = str.size();
        helper(str,k,0,n);
        return ans;
       // code here.
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends