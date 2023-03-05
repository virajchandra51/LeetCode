class Solution {
public:
    bool palindrome(string s){
        if(s.length()==0)return false;
        int i=0, j=s.length()-1;
        while(i<j)if(s[i++]!=s[j--])return false;
        return true;
    }
    int solve(int i, int j, string&s, string&s1, string&s2){
        if(i>=s.length() || j>=s.length()){
            if(palindrome(s1)&&palindrome(s2)){
                return s1.length()*s2.length();
            }
            return 0;
        }
        int notake=solve(i+1, j+1, s, s1, s2);
        s1.push_back(s[i]);
        int take1=solve(i+1, j+1, s, s1, s2);
        s1.pop_back();
        s2.push_back(s[j]);
        int take2=solve(i+1, j+1, s, s1, s2);
        s2.pop_back();
        int take=max(take1, take2);
        return max(take, notake);
    }
    int maxProduct(string s) {
        string s1="", s2="";
        return solve(0, 0, s, s1, s2);
    }
};