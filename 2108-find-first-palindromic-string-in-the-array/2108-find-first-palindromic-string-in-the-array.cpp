class Solution {
public:
    bool pal(string s){
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[s.size()-i-1])
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto it:words)
        {
            if(pal(it))
                return it;
        }
        return "";
    }
};