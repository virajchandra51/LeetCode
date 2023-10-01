class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int len = 0;
        int l = 0, r = 0;
        unordered_set <char> st;
        while (r < n)
        {
            if (st.find(s[r])== st.end()) 
            st.insert(s[r]);
            else {
                 while (st.find(s[r]) != st.end()) {
                 st.erase(s[l]);
                 l++;
                 }
            st.insert(s[r]);
                 } 
            len = max(len, r - l + 1);
            r++;
        }
        return len;
    }
};