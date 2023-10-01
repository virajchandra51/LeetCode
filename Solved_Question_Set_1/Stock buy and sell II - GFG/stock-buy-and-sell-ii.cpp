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
    vector<vector<int>> dp;
    int helper(int i, bool bought, vector<int>& prices, int n)
    {
        if(i>=n) return 0;
        if(dp[bought][i]!=-1) return dp[bought][i];
        int sum = helper(i+1,bought,prices,n);
        if(bought)
        sum=max(sum,helper(i+1,false,prices,n)+prices[i]);
        else sum=max(sum,helper(i+1,true,prices,n)-prices[i]);
        return dp[bought][i] = sum;
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        dp.resize(3,vector<int>(n+1,-1));
        return helper(0,false,prices,n);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends