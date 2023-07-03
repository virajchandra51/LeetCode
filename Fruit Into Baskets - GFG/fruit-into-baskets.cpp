//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        map<int,int> m;
        int i=0;
        int j=0;
        int ans = 0;
        while(j<N && i<N)
        {
            m[fruits[j]]++;
            if(m.size()<=2)
            {
                ans=max(ans,j-i+1);
            }
            else
            {
                while(m[fruits[i]]>0)
                {
                    m[fruits[i]]--;
                    if(m[fruits[i]]==0)
                    {
                        m.erase(fruits[i]);
                        break;
                    }
                    i++;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends