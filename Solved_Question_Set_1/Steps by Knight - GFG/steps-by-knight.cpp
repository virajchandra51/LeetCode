//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isValid(vector<vector<int>> &vis, int i, int j, int n)
    {
        if(i<0 || j<0 || i>=n || j>=n || vis[i][j]==1)
        return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&k,vector<int>&t,int N)
	{
	    vector<vector<int>> vis(N,vector<int>(N,0));
	    swap(t[0],t[1]);
	    t[0] = (N-t[0]);
	    t[1]--;
	    queue<pair<int,pair<int,int>>> q;
	    q.push({0,{N-k[1],k[0]-1}});
	    vis[N-k[1]][k[0]-1]=1;
	    while(!q.empty())
	    {
	        int dx[] = {-1,-2,-2,-1,+1,+2,+2,+1};
	        int dy[] = {+2,+1,-1,-2,-2,-1,+1,+2};
	        pair<int,pair<int,int>> p = q.front();
	        q.pop();
	        if(p.second.first==(t[0]) && p.second.second==(t[1]))
	        return p.first;
	        for(int i=0;i<8;i++)
	        {
	            int x = p.second.first+dx[i];
	            int y = p.second.second+dy[i];
	            if(isValid(vis,x,y,N))
	            {
	                vis[x][y] = 1;
	                q.push({p.first+1,{x,y}});
	                q.push({p.first+1,{x,y}});
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends