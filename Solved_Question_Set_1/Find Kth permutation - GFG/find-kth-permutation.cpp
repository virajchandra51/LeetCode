//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> fac(n+1,1);
        for(int i=2;i<=n;i++) fac[i]*=(fac[i-1]*i);
        string a = "";
        vector<string> v(n);
        for(int i=0;i<n;i++)
        v[i] = to_string(i+1);
        int o = -1;
        int ff = 0;
        while(a.size()<n)
        {
            int f = ceil(1.0*k/fac[n-ff-1]);
            int c = f;
            for(int i=0;i<n;i++)
            {
                if(v[i]!="-1")
                {
                    f--;
                    if(f==0)
                    {
                        a+=v[i];
                        v[i]="-1";
                        break;
                    }
                }
                else continue;
            }
            k-=((c-1)*(fac[n-ff-1]));
            ff++;
        }
        return a;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends