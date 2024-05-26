class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int,int> hashTable;
        for(auto number : nums1){
            for(int i = 1; i * i <= number; i++){
                if(i * i == number){
                    hashTable[i]++;
                }else if(number % i == 0){
                    hashTable[i]++;
                    hashTable[number / i]++;
                }
            }
            
        }
        long long int answer = 0;
        for(auto number : nums2){
            number *= k;
            if(hashTable[number] > 0){
                answer += hashTable[number];
            }
        }
        return answer;
    }
};