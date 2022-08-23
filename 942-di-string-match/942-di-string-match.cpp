class Solution {
public:
    vector<int> diStringMatch(string s) {
        int l=0,r=s.size();
        vector<int> v;
        for(auto it:s)
        {
            if(it=='I')
            {
                v.push_back(l);
                l++;
            }
            else
            {
                v.push_back(r);
                r--;
            }
        }
        v.push_back(r);
        return v;
    }
};