//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    bool isH(vector<int> &m1, vector<int> &m2)
    {
        for(int i=0;i<26;i++)
        {
            if(m1[i]>m2[i]) return false;
        }
        return true;
    }
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int> m1(26,0),m2(26,0),m3(26,0);
        // unordered_map<char,int> m;
        for(auto it:p)
        {
            m1[it-'a']++;
            // m[it]=1;
        }
        for(auto it:s)
        {
            m3[it-'a']++;
        }
        if(!isH(m1,m3)) return "-1";
        int id = 0;
        int si = INT_MAX;
        int i=0;
        int j=0;
        int n = s.size();
        while(j<n)
        {
            m2[s[j]-'a']++;
            while(isH(m1,m2))
            {
                if((j-i+1)<si)
                {
                    si=j-i+1;
                    id=i;
                }
                m2[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return s.substr(id,si);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends