class Solution {
public:

    
//     a b c 
//   0 0 0 0 
// d 0 0 0 0 1 1
// e 0 0 0 0 2 2  
// f 0 1 1 2 2 3 
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0) curr[j] = 0;
                else if(text1[i-1]==text2[j-1])
                curr[j] = 1+prev[j-1];
                else
                curr[j] = max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
    }
};