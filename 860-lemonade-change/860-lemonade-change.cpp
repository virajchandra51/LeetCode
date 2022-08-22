class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int b5=0,b10=0;
        for(auto it:bills)
        { 
            if(it==5)
                b5++;
            else if(it==10)
            {
                if(b5>0)
                {
                    b10++;
                    b5--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(b5>0 && b10>0)
                {
                    b5--;
                    b10--;
                }
                else if(b5>2)
                {
                    b5-=3;
                }
                else
                {
                    return false;
                }
            }
            cout<<b5<<" "<<b10<<endl;
        }
        return true;
    }
};