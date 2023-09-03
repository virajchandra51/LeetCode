class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string a = "";
        string b = "";
        string c = "";
        string d = "";
        int n1 = s1.size();
        int n2 = s2.size();
        for(int i=0;i<n1;i++)
        {
            if(i&1) a+=s1[i]; else b+=s1[i];
        }
        for(int i=0;i<n2;i++)
        {
            if(i&1) c+=s2[i]; else d+=s2[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());
        return a==c && b==d;
    }
};