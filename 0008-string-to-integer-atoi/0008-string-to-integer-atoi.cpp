class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool neg = false;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch == ' '){if(i != 0 && s[i-1] != ' ') break; continue;}
            else if(ch == '-'){if(i != 0 && s[i-1] != ' ') break; neg = true;}
            else if(ch == '+'){if(i != 0 && s[i-1] != ' ') break; neg = false;}
            else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '.') break;
            else{
                if(neg){
                    ans = 10*ans - int(ch - '0');
                    if(ans < INT_MIN) return INT_MIN;
                }
                else{
                    ans = 10*ans + int(ch - '0');
                    if(ans > INT_MAX) return INT_MAX;
                }
            }
        }
        return ans;
    }
};