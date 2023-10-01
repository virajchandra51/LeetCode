//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMaximum(int n, vector<int> &arr) {
        // code here
        long long s = 0;
        for(auto it:arr) s+=it;
        long long ans = INT_MIN;
        int f;
        for(long long i=1;i*i<=s;i++)
        {
            if(s%i==0)
            {
                long long bow1 = s/i;
                long long bow2 = i;
                if(bow1<=n) ans=max(ans,bow1);
                if(bow2<=n) ans=max(ans,bow2);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.getMaximum(N, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends