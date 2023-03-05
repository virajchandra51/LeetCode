class Solution {
public:
    bool isValid(int n){
        bool flag=false;
        while(n){
            int x=n%10;
            n/=10;
            if(x!=2 && x!=5 && x!=6 && x!=9 && x!=0 && x!=1 && x!=8)return false;
            if(x==2 || x==5 || x==6 || x==9)flag=true;
        }return flag;
    }
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)if(isValid(i))ans++;
        return ans;
    }
};