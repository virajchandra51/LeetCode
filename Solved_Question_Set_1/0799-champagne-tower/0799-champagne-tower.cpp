class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        double v[101][101] = {0.0};
        
        v[0][0] = poured;
        
        for(int i =0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(v[i][j]>1)
                {
                v[i+1][j]+= (v[i][j]-1)/2.0;
                v[i+1][j+1]+= (v[i][j]-1)/2.0;
                v[i][j]=1;
                }
            }
        }
        return v[query_row][query_glass];
        
    }
};