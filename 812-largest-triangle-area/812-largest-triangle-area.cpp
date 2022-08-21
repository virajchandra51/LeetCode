class Solution {
public:double area(vector<int> a, vector<int> b, vector<int> c){
        return 0.5 * abs(a[0]*(b[1] - c[1]) + b[0]*(c[1] - a[1]) + c[0]*(a[1] - b[1]));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double max = 0;
        
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                for(int z=j+1; z<points.size(); z++){
                    if(area(points[i], points[j], points[z]) > max) max = area(points[i], points[j], points[z]);
                }
            }
        }
        
        return max;
        
    }
   
};