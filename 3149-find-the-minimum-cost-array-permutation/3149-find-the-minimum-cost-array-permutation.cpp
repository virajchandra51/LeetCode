const int N = 14;
const int MX = 1 << N;
int dp[N][MX][N];

class Solution {
public:
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        int target_mask = (1 << n) - 1;
        const int NP = 1e5;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<(target_mask+1);j++)
            {
                for(int k=0;k<n;k++) dp[i][j][k]=NP;
            }
        }
        
        auto solve = [&] (auto &&solve, int first, int mask, int last) {
            if (mask == target_mask) return dp[first][mask][last] = abs(last - nums[first]);
            if (dp[first][mask][last] != NP) return dp[first][mask][last];
            
            int min_cost = NP;
            
            for (int curr = 0; curr < n; curr++) {
                if (mask >> curr & 1) continue;
                int nmask = mask | (1 << curr);
                int cost = abs(last - nums[curr]) + solve(solve, first, nmask, curr);
                min_cost = min(min_cost, cost);
            }
            
            return dp[first][mask][last] = min_cost;
        };
        
        int ans = NP, best;
        for (int i = 0; i < n; i++) {
            int curr = solve(solve, i, 1 << i, i);
            if (curr < ans) {
                ans = curr;
                best = i;
            }
        }
        
        vector<int> perm{best};
        
        auto findPerm = [&] (auto &&findPerm, int first, int mask, int last) {
            if (mask == target_mask) return;
            int next, min_cost = NP;
            for (int curr = 0; curr < n; curr++) {
                if (mask >> curr & 1) continue;
                int nmask = mask | (1 << curr);
                int cost = abs(last - nums[curr]) + solve(solve, first, nmask, curr);
                if (cost < min_cost) {
                    min_cost = cost;
                    next = curr;
                }
            }
            perm.push_back(next);
            findPerm(findPerm, first, mask | (1 << next), next);
        };
        findPerm(findPerm, best, 1 << best, best);
        
        return perm;
    }
};