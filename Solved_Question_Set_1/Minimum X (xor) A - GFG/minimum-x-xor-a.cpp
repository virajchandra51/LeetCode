//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int c=0;
        while(b)
        {
            if(b%2) c++;
            b>>=1;
        }
        vector<int> abits;
        while(a)
        {
            abits.push_back(a%2);
            a>>=1;
        }
        reverse(abits.begin(),abits.end());
        vector<int> ansb(abits.size(),0);
        for(int i=0;i<abits.size();i++)
        {
            if(abits[i]==1)
            {
                if(c>0)
                {
                    ansb[i]=1;
                    c--;
                }
                else
                {
                    break;
                }
            }
        }
        for(int i=abits.size()-1;i>=0;i--)
        {
            if(ansb[i]==0)
            {
                if(c>0)
                {
                    ansb[i]=1;
                    c--;
                }
                else
                {
                    break;
                }
            }
        }
        int res=0;
        reverse(ansb.begin(),ansb.end());
        for(int i=0;i<ansb.size();i++)
        {
            res+=(pow(2,i)*ansb[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends