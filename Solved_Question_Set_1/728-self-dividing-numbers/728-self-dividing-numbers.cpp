class Solution {
public:
    bool self(int n)
    {
        int temp = n;
        while(n>0)
        {
            if(n%10==0)
                return false;
            if(temp%(n%10)!=0)
                return false;
            n/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++)
        {
            if(self(i))
                ans.push_back(i);
        }
        return ans;
    }
};