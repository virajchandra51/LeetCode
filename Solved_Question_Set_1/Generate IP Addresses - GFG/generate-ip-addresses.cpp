//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<string> ans;
    void helper(string s, int n , int i, int leftdot, string curr, string a)
    {
        if(i>=n)
        {
            if(leftdot==0 && stoi(curr)<=255 && stoi(curr)>=0)
                {
                    ans.push_back(a+curr);
                }
                return;
        }
        if(curr.size()==0)
        {
            helper(s,n,i+1,leftdot,curr+s[i],a);
        }
        else
        {
            if(stoi(curr)==0)
            {
                if(leftdot>0)
                helper(s,n,i,leftdot-1,"",a+"0.");
            }
            else
            {
                if(stoi(curr+s[i])<=255 && stoi(curr+s[i])>=0)
                helper(s,n,i+1,leftdot,curr+s[i],a);
                if(leftdot>0 && stoi(curr)<=255 && stoi(curr)>=0)
                {
                    helper(s,n,i,leftdot-1,"",a+curr+".");
                }
            }
        }
    }
    vector<string> genIp(string &s) {
        helper(s,s.size(),0,3,"","");
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends