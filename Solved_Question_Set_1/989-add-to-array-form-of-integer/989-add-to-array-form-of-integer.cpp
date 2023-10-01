class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int i = num.size()-1;
        int carry=0;
        while(k>0 && i>=0)
        {
            int sum = num[i]+k%10+carry;
            if(sum>9)
            {
                sum%=10;
                carry=1;
            }
            else
                carry=0;
            ans.push_back(sum);
            k/=10; i--;
        }
        while(i>=0)
        {
            int sum = num[i]+carry;
            if(sum>9)
            {
                sum%=10;
                carry=1;
            }
            else
                carry=0;
            ans.push_back(sum);
            i--;
        }
        while(k>0)
        {
            int sum = k%10+carry;
            if(sum>9)
            {
                sum%=10;
                carry=1;
            }
            else
                carry=0;
            ans.push_back(sum);
            k/=10;
        }
        if(carry==1)
            ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};