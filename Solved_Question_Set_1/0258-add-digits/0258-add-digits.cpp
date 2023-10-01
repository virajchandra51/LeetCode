class Solution {
public:
    int addDigits(int num) {
            int sum=0;
        while(num>0)
        {
            sum+=(num%10);
            num/=10;
        }
        
            while(sum>=10)
            {
                int temp=sum;
                sum=0;
                while(temp>0)
                {
                    sum+=(temp%10);
                    temp/=10;
                }
                
            }
        return sum;
        
    }
};