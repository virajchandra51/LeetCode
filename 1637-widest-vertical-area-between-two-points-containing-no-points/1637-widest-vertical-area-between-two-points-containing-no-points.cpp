class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int m = 0;
        for(int i=0;i<points.size()-1;i++)
            m=max(m,points[i+1][0]-points[i][0]);
        return m;
    }
};