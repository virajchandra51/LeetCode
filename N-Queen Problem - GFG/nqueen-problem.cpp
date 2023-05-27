//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> res;
    bool isSafe(vector<vector<int>> &board, int row, int col)
    {
        int n = board.size();
        int i,j;
        for(i=0;i<n;i++)
        if(board[row][i]) return false;
        for(i=0;i<n;i++)
        if(board[i][col]) return false;
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
        for (i = row, j = col; i < n && j < n; i++, j++)
        if (board[i][j]) return false;
        for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j]) return false;
        for (i = row, j = col; j < n && i>=0; i--, j++)
        if (board[i][j]) return false;
        return true;
    }
    bool isP(vector<vector<int>>& board, int col)
    {
        int n = board.size();
        if(col==n)
        {
            vector<int> v;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(board[i][j])
                    v.push_back(j+1);
                }
            }
            res.push_back(v);
            return true;
        }
        bool r = false;
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,i,col))
            {
                board[i][col] = 1;
                r=isP(board,col+1)|r;
                board[i][col] = 0;
            }
        }
        return r;
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n,vector<int>(n,0));
        if(isP(board,0)==false) return {};
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends