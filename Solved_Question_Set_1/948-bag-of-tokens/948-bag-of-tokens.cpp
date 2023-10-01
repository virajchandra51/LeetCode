class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int l=0,h=tokens.size()-1;
        int point=0,ans=0;
        while(l<=h && (power>=tokens[l] || point>0))
        {
            while(l<=h && power>=tokens[l])
            {
                power-=tokens[l++];
                point++;
            }
            ans=max(ans,point);
            if(l<=h && point>0)
            {
                power+=tokens[h--];
                point--;
            }
        }
        return ans;
    }
};