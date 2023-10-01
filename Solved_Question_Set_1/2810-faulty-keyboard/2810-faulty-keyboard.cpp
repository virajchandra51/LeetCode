class Solution {
public:
    string finalString(string s) {
        string a = "";
        for(auto it:s)
        {
            if(it!='i') a+=it;
            else reverse(a.begin(),a.end());
        }
        return a;
    }
};