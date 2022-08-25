class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = 0;
        for(auto a : arr){
            total += a;
        }
        if(total %3 != 0 ) return false;
        int sum = 0, part = 3 ;
        for(int a : arr){
            sum += a;
            if(sum == total/3) {
                part--; 
                sum = 0;
            }
        }
        return part<=0;
    }
};