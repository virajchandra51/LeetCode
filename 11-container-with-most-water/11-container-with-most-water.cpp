class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r= height.size()-1; int m=-1;
        while(l<r)
        {
            m=max(m,(r-l)*(min(height[l],height[r])));
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return m;
    }
};