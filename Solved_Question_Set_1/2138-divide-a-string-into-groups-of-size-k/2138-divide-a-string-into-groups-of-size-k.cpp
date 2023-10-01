class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;
        for(int i=0;i<s.size();i+=k)
        {
            v.push_back(s.substr(i,k));
        }
        if(s.size()%k!=0)
        {
            v.pop_back();
            string a ="";
            a+=(s.substr((s.size()/k)*k));
            for(int i=1;i<=(k-(s.size()-(s.size()/k)*k));i++)
                a+=fill;
            v.push_back(a);
        }
        return v;
    }
};