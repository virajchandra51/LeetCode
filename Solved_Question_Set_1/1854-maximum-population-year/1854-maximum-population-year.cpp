class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        sort(logs.begin(),logs.end());
        int ans= logs[0][0];
        int m = 1;
        for(int i=logs[0][0];i<=logs[logs.size()-1][1];i++)
        {
            int c=1;
            for(int j=0;j<logs.size();j++)
            {
                if(logs[j][0]<=i && i<logs[j][1])
                    c++;
            }
            if(c>m)
            {
                m=c;
                ans=i;
            }
        }
        return ans;
    }
};