class Solution {
public:
    string F(string num)
    {
        int c=1; string ans="";
        for(int i=1;i<num.size();i++)
        {
            if(num[i]==num[i-1])
                c++;
            else
            {
                ans+=(to_string(c*10+(int)(num[i-1]-48)));
                c=1;
            }
        }
        ans+=(to_string(c*10+(int)(num[num.size()-1]-48)));
        return ans;
    }

    string countAndSay(int n) {
        string fi = "1"; string m = "1";
        for(int i=1;i<n;i++)
        {
            fi = F(m);
            m=fi;
        }
        return fi;
    }
};