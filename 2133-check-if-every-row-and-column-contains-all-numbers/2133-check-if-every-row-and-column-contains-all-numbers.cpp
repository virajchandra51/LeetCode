class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int sum = N * (N + 1) / 2; //Calculate sum of numbers from 1 to N
        
        for(int i{0}; i < N; i++){ 
            int col_sum{0};
            int row_sum{0};
            unordered_map<int, int> freq{};
            
            for(int j{0}; j < N; j++){
                row_sum += matrix[i][j];
                col_sum += matrix[j][i];
				freq[matrix[i][j]]++;
                
                if(freq[matrix[i][j]] == 2)
                    return false;
            }
            
            if(row_sum != sum || col_sum != sum)
                return false;
        }
        
        return true;
    }
};