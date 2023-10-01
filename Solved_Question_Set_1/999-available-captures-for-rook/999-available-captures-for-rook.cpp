class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int c=0;
        int id=-1,ij=-1;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='R')
                {
                    id=i;
                    ij=j;
                }
            }
        }
        for(int j=ij;j<board[0].size();j++)
        {
            if(board[id][j]=='B')
                break;
            if(board[id][j]=='p')
            {
                c++;break;
            }
        }
        for(int j=ij-1;j>=0;j--)
        {
            if(board[id][j]=='B')
                break;
            if(board[id][j]=='p')
            {
                c++;break;
            }
        }
        for(int i=id-1;i>=0;i--)
        {
            if(board[i][ij]=='B')
                break;
            if(board[i][ij]=='p')
            {
                c++;break;
            }
        }
        for(int i=id+1;i<board.size();i++)
        {
            if(board[i][ij]=='B')
                break;
            if(board[i][ij]=='p')
            {
                c++;break;
            }
        }
        return c;
    }
};