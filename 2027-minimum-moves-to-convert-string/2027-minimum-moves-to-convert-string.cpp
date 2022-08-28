class Solution {
public:
    int minimumMoves(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){if(s[i]=='O') continue;
            for(int j=i;j<i+3 && j<s.size();j++){if(s[j]=='X'){ ans+=1;i=i+2;break;}}}
        return ans;
    }
};