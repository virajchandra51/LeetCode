class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        set<int> s;
        long long ans = 1;
        int curr = 1;
        s.insert(1);
        int i=1;
        while(i<n)
        {
            curr++;
            if(s.find(target-curr)!=s.end())
                continue;
            ans+=curr;
            i++;
            s.insert(curr);
        }
        return ans;
    }
};