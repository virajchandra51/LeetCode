class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans1 = 0;
        int ans2 = 0;
        for(auto it:moves)
        {
            if(it=='R') ans1--;
            else ans1++;
        }
        for(auto it:moves)
        {
            if(it=='L') ans2--;
            else ans2++;
        }
        return max(ans1,ans2);
    }
};