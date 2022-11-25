class Solution {
public:
    // 1 2 3 4 5 6 7 8 9 1 0 1 1 1 2 1 3 1 4
    int findNthDigit(int n) {
        long b = 9;
        long d = 1;
        if(n<=9)
            return n;
        while(n-(b*d)>0)
        {
            n-=(b*d);
            d++;
            b*=10;
        }
        long num = 1;
        cout<<d<<endl;
        for(int i=1;i<d;i++)
            num*=10;
        cout<<num<<endl;
        num+=(n/d);
        if(n%d==0)
            num--;
        cout<<num<<endl;
        int id = n%d;
        if(id==0)
            return num%10;
        id = d-id;
        for(int i=0;i<id;i++)
            num/=10;
        return num%10;
    }
};