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
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        if(N==1) return {0};
        vector<int> pre(N+2,0);
        vector<int> suf(N+2,0);
        set<int> s;
        for(int i=1;i<=N;i++)
        {
            if(s.find(A[i-1])==s.end())
            pre[i]=pre[i-1]+1;
            else
            pre[i]=pre[i-1];
            s.insert(A[i-1]);
        }
        s.clear();
        for(int i=N;i>=1;i--)
        {
            if(s.find(A[i-1])==s.end())
            suf[i]=suf[i+1]+1;
            else
            suf[i]=suf[i+1];
            s.insert(A[i-1]);
        }
        
        vector<int> ans;
        for(int i=1;i<=N;i++)
        ans.push_back(pre[i-1]-suf[i+1]);
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
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends