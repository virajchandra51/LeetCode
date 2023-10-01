class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int sum = 0, n = grid.size(), diag_sum = 0;
            // traverse through the matrix
        for(int i = 0; i < n;  i ++) {
            
            for(int j = 0; j < n; j ++) {
                
                sum = sum + grid[i][j]; 
                // the condition for diagonal elements 
                if (i == j || i == n-1-j) {
                    if (grid[i][j] == 0)         // if any diagonal element is zero return false
                        return false;
                    else                            // else calculate the sum of diagonal elements
                        diag_sum = grid[i][j] + diag_sum;
               }
            }
        }
        
        if (sum == diag_sum) {        // if sum of diagonal elements is equal to sum of all elements 
            return true;                     // this means all the elements outside diagonals are zero in the matrix
        }
        else                                    // else we return false
            return false;
    }
};