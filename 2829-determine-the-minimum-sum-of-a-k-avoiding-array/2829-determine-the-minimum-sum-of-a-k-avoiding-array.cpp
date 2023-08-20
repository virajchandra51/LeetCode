class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int> a;
        set<int> s;
        int size=0;
        int curr=1;
        int ans =0;
        while(size<n)
        {
            if(s.find(k-curr)!=s.end())
            {
                curr++;
            }
            else
            {
                ans+=curr;
                size++;
                s.insert(curr);
                curr++;
            }
        }
        return ans;
    }
};