class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        set<int>s;
        int n=arr.size(), ans=0;
        vector<int>dp(n);
        for(int i=0;i<n;i++)s.insert(arr[i]);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=arr[i], b=arr[j];
                int l=2;
                while(s.count(a+b)){
                    b=a+b;a=b-a;l++;
                }
                ans=max(ans, l);
            }
        }return ans>2?ans:0;
    }
};