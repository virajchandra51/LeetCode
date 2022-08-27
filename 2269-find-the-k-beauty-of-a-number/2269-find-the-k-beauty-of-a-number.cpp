class Solution {
public:
    int divisorSubstrings(int num, int k) {
          int n=num;
    int count=0;
    long mod=pow(10,k);
    while(n>=mod/10){
        int div=n%mod;
        if(div!=0 && num%div==0)count++;
        n=n/10;
    }
    return count;
    }
};