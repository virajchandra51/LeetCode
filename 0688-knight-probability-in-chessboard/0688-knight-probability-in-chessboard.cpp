class Solution {
public:
    bool isInBoard(int i, int j, int n){
        if(i>=0 && j>=0 && i<n && j<n)return true;
        return false;
    }
    double solve(int i,int j,int k,int n,vector<vector<vector<double>>>&dp){
        if(!isInBoard(i, j, n))return 0;
        if(k==0)return isInBoard(i, j, n);
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        double ans=0;
        ans+=solve(i-2, j+1, k-1, n, dp);
        ans+=solve(i-1, j+2, k-1, n, dp);
        ans+=solve(i+1, j+2, k-1, n, dp);
        ans+=solve(i+2, j+1, k-1, n, dp);
        ans+=solve(i+2, j-1, k-1, n, dp);
        ans+=solve(i+1, j-2, k-1, n, dp);
        ans+=solve(i-1, j-2, k-1, n, dp);
        ans+=solve(i-2, j-1, k-1, n, dp);
        return dp[i][j][k]=ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        double ans=solve(row, column, k, n, dp);
        return ans/pow(8, k);
    }
};