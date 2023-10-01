class Solution {
public:
    void kmp(string s, vector <int> &k) {
        k[0] = 0;
        int n = s.size();
        
        for(int i = 1; i < n; i++) {
            int t = k[i - 1];
            
            while(t > 0 && s[t] != s[i])
                t = k[t - 1];
            
            if(s[t] == s[i])
                t++;
            k[i] = t;
        }
    }
    
    int strStr(string s, string t) {
        if(t == "")
            return 0;
        
        int n = s.size(), m = t.size();
        string temp = t + '#' + s;
        cout<<temp<<" ";
        vector <int> k(temp.size());
        
        kmp(temp, k);
        
        for(auto it:k) cout<<it<<" ";
        int res = INT_MAX;
        for(int i = m + 1; i < n + m + 1; i++) {
            if(k[i] == m)
                return i - k[i] + 1 - m - 1;
        }
        
        return -1;
    }
};