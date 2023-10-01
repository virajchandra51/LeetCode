class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int i=0,j=0;
        vector<vector<int>> ans;
        while(j<s.size())
        {
            if(s[j+1]==s[i])
            {
                j++;
            }
            else
            {
                cout<<i<<" "<<j<<endl;
                if((j-i+1)>=3)
                {
                    vector<int> a;
                    a.push_back(i);
                    a.push_back(j);
                    ans.push_back(a);
                }
                i=j+1;
                j++;
            }
        }
        return ans;
    }
};