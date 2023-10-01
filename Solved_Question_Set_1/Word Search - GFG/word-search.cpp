//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool ans = false;
    void helper(vector<vector<char>>& board,string word, int in, int s, int i, int j, int n, int m)
    {
        if(in==(s-1))
        {
            ans=true;
            return;
        }
        char ch = board[i][j];
        board[i][j] = '*';
        if(in+1<s && j+1<m && board[i][j+1]==word[in+1])
        helper(board,word,in+1,s,i,j+1,n,m);
        if(in+1<s && j-1>=0 && board[i][j-1]==word[in+1])
        helper(board,word,in+1,s,i,j-1,n,m);
        if(in+1<s && i+1<n && board[i+1][j]==word[in+1])
        helper(board,word,in+1,s,i+1,j,n,m);
        if(in+1<s && i-1>=0 && board[i-1][j]==word[in+1])
        helper(board,word,in+1,s,i-1,j,n,m);
        board[i][j] = ch;
        return;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n = board.size();
        int m = board[0].size();
        int i = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    helper(board,word,0,word.size(),i,j,n,m);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends