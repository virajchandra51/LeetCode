class Solution {
public:
    void mult(vector<vector<int>> &m1, vector<vector<int>> &m2)
    {
        vector<vector<int>> temp(2,vector<int>(2,1));
        temp[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
        temp[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
        temp[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
        temp[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];
        m1 = temp;
    }
    void mat_power(vector<vector<int>>& m, int n)
    {
        if(n==1) return;
        mat_power(m,n/2);
        mult(m,m);
        vector<vector<int>> mm = {{1,1},{1,0}};
        if(n&1)
        mult(m,mm);
    }
    int fib(int n) {
        vector<vector<int>> m = {{1,1},{1,0}};
        if(n==0) return 0;
        mat_power(m,n);
        return m[0][1];
    }
};