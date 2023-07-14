class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for(auto &it:time) 
        it%=60;
        int c = 0;
        int n = time.size();
        map<int,int> m;
        for(auto it:time)
        {
            if(it==0)
            {
                c+=m[0];
            }
            else
            {
                if(m.find(60-it)!=m.end())
                {
                    c+=((m[60-it]));
                }
            }
            m[it]++;
        }
        return c;
    }
};