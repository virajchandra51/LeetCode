class Solution {
public:
    vector<int> count(int n){
        vector<int> ans(10);
        while(n>0)
        {
            ans[n%10]++;
            n/=10;
        }
        return ans;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> num = count(n);
        for(int i=0;i<31;i++)
        {
            if(num==(count(1<<i)))
                return true;
        }
        return false;
    }
};