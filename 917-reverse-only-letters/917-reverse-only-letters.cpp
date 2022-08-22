class Solution {
public:
    string reverseOnlyLetters(string s) {
        string ans=s;
        int start=0;
        int end=s.length()-1;
        while(start<=end)
        {
           if(isvalid(s[start])==true and isvalid(s[end])==true)
           {
               ans[start]=s[end];
               ans[end]=s[start];
               start++;
               end--;
           }
           else if(isvalid(s[start])==false and isvalid(s[end])==true)
           {
               start++;
           }
           else if(isvalid(s[start])==true and isvalid(s[end])==false)
           {
               end--;
           }
           else if(isvalid(s[start])==false and isvalid(s[end])==false)
           {
               start++;
               end--;
           }
        }
        return ans;
    }
    bool isvalid(char ch)
    {
        if((ch>='a' and ch<='z') || (ch>='A' and ch<='Z'))
        {
            return true;
        }
        return false;
    }
};