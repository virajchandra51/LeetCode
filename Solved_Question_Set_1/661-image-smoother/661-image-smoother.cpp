class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size(),vector<int> (img[0].size()));
        for(int i=0;i<img.size();i++)
        {
            for(int j=0;j<img[0].size();j++)
            {
                int sum = img[i][j];
                int c = 1;
                if(i-1>=0 && j-1>=0)
                {
                    sum+=(img[i-1][j-1]);
                    c++;
                }
                if(i-1>=0)
                {
                    sum+=(img[i-1][j]);
                    c++;
                }
                if(i-1>=0 && j+1<img[0].size())
                {
                    sum+=(img[i-1][j+1]);
                    c++;
                }
                if(j-1>=0)
                {
                    sum+=(img[i][j-1]);
                    c++;
                }
                if(j+1<img[0].size())
                {
                    sum+=(img[i][j+1]);
                    c++;
                }
                if(i+1<img.size() && j-1>=0)
                {
                    sum+=(img[i+1][j-1]);
                    c++;
                }
                if(i+1<img.size())
                {
                    sum+=(img[i+1][j]);
                    c++;
                }
                if(i+1<img.size() && j+1<img[0].size())
                {
                    sum+=(img[i+1][j+1]);
                    c++;
                }
                ans[i][j] = sum/c;
            }
        }
        return ans;
    }
};