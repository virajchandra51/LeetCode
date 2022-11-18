class Solution {
public:
    bool isUgly(int n) {
        while(n>1){
            if(n%5==0)n/=5;
            else if(n%3==0)n/=3;
            else if(n%2==0)n/=2;
            else break;
        }
        if(n==1)return true;
        else return false;
    }
};