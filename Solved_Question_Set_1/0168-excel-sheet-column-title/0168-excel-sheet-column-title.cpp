class Solution {
public:
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string convertToTitle(int columnNumber) {
        string ans="";
        int remainder=0;
        while(columnNumber>0){
            remainder=columnNumber%26;
            if(remainder==0){
                ans+=s[25];
                columnNumber-=26;
            } 
            else{
            ans+=s[remainder-1];
            } 
            columnNumber-=remainder;
            columnNumber=columnNumber/26; 
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};