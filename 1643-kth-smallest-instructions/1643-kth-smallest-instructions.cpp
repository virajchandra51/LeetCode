class Solution {
public:
    string kthSmallestPath(vector<int>& d, int k) {
        vector<long double> fac(31,1);
        fac[0]=1;
        fac[1]=1;
        for(int i=2;i<31;i++)
            fac[i]=(i*fac[i-1]);
        long long currH = d[1];
        long long currV = d[0];
        long long total = currH+currV;
        string a = "";
        while(total>0)
        {
            if(currH>0)
            {
                long long ifH = fac[total-1]/fac[currH-1]/fac[currV];
                if(ifH>=k)
                {
                    a+="H";
                    currH--;
                    total--;
                }
                else
                {
                    k-=ifH;
                    a+="V";
                    currV--;
                    total--;
                }
            }
            else
            {
                for(int i=0;i<currV;i++)
                    a+="V";
                break;
            }
        }
        return a;
    }
};