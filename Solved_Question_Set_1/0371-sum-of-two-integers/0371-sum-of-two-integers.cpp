class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            unsigned int temp = (a & b);
            a = (a ^ b);
            b = temp << 1;
        }
        return a;
    }
};