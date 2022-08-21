class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int sum=0;
        int c=0;
        for(int i=0;i<s.size();i++)
        {
            sum+=(widths[s[i]-'a']);
            if(sum>100)
            {
                sum-=(widths[s[i]-'a']);
                c++;
                sum=0;
                sum+=(widths[s[i]-'a']);   
            }
        }
        return {c+1,sum};
    }
};