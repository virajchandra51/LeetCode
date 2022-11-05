class Solution {
public:
    bool ans = false;
    void dfs(int i, int j, int r, int c, string word, vector<vector<char>> & board,int index)
    {
        
        if(index==word.size())
        {
            ans=true;return;
        }
        if(i<0 || i>=r || j<0 || j>=c || board[i][j]=='$' || word[index]!=board[i][j])
            return;
        
        char ch = board[i][j];
        board[i][j] = '$';
        dfs(i+1,j,r,c,word,board,index+1);
        dfs(i-1,j,r,c,word,board,index+1);
        dfs(i,j+1,r,c,word,board,index+1);
        dfs(i,j-1,r,c,word,board,index+1);
        board[i][j]=ch;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==word[0])
                {
                    dfs(i,j,r,c,word,board,0);
                    if(ans)
                        return true;
                }
            }
        }
        return false;
    }
};