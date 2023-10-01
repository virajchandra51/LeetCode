//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
          int len=s.length();

        vector<vector<string>>ans;

        int i=0;

        while(i<len)

        {

            set<string>v;

            for(int j=0;j<n;j++)

            {

                if(contact[j]!="*" and i<contact[j].length() and contact[j][i]==s[i])

                {

                    v.insert(contact[j]);

                }

                else

                {

                    contact[j]="*";

                }

            }

            i++;

            vector<string>v1;

            for(auto &it:v)

            {

                v1.push_back(it);

            }

            if(v1.empty())

            {

                v1.push_back("0");

            }

            ans.push_back(v1);

        }

        return ans;

    
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends