class Solution {
public:
    int maxSumSubarray(vector<int>& v, int k)
    {
        set<int> s;
        s.insert(0);
        int prefixSum=0;
        int ans=INT_MIN;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            prefixSum+=v[i];
            auto it = s.lower_bound(prefixSum - k);
            if(it != s.end())
            {
                ans = max(ans, prefixSum - *it);
            }
            s.insert(prefixSum);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
         int n = matrix.size();
        
        int m = matrix[0].size();
        
        int maxi = INT_MIN;
        
        // fix the position of two rows and take cumulative sum of columns between two fixed rows
        
        for(int start_row = 0; start_row < n; start_row++)
        {
            vector<int> col_array(m, 0);
            
            for(int end_row = start_row; end_row < n; end_row++)
            {
                // take cumulative sum of columns between two fixed rows
                
                for(int col = 0; col < m; col++)
                {
                    col_array[col] += matrix[end_row][col];
                }
                
                // find maximum subarray having sum less than equal to k
                
                int curr_max = maxSumSubarray(col_array, k);
                
                // update the maximum sum
                
                maxi = max(maxi, curr_max);
            }
        }
        
        return maxi;
    }
};