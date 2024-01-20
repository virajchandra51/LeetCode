class Solution {
public:
    long long m = 1337;
    long long binaryExpo(long long a, long long power)
    {
        long long result = 1;
        while(power>0)
        {
            if(power%2 == 1)
            {
                result = ((result%m) * (a%m))%m;
            }
            a = ((a%m) * (a%m))%m;
            power>>=1;
        }
        return result;
    }
    int superPow(int a, vector<int>& b) {
        int result = 1;
        for(auto digit:b)
        {
            result = (binaryExpo(result,10)%m * binaryExpo(a,digit)%m)%m;
        }
        return result;
    }
};