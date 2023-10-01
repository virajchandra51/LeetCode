class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0.0;
        for(int i=0;i<brackets.size();i++)
        {
            if(i==0)
            {
                if(brackets[i][0]>income)
                {
                    ans+=(income*brackets[i][1]*0.01);break;
                }
                else
                {
                    ans+=(brackets[i][0]*brackets[i][1]*0.01);
                }
            }
            else
            {
                if(brackets[i][0]>income)
                {
                    ans+=((income-brackets[i-1][0])*brackets[i][1]*0.01);break;
                }
                else
                {
                    ans+=((brackets[i][0]-brackets[i-1][0])*brackets[i][1]*0.01);
                }
            }
        }
        return ans;
    }
};