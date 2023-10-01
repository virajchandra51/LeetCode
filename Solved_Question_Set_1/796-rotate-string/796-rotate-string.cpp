class Solution {
public:
    bool rotateString(string s, string goal) {
        string t = s;
        t = t.substr(1,t.size()-1)+t[0];
        while(t!=s)
        {
            if(t==goal)
                return true;
            t = t.substr(1,t.size()-1)+t[0];
        }
        return false;
    }
};