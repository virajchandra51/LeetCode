class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m1,m2;
        for(auto it:arr)
            m1[it]++;
        for(auto it:m1)
            m2[it.second]++;
        for(auto it:m2)
        {
            if(it.second!=1)
                return false;
        }
        return true;
    }
};