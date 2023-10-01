class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0;i<image.size();i++)
        {
            for(int j=0;j<image[0].size()/2;j++)
            {
                swap(image[i][j],image[i][image[0].size()-j-1]);
                image[i][j]=!image[i][j];
                image[i][image[0].size()-j-1]=!image[i][image[0].size()-j-1];
            }
            if(image[0].size()&1)
                image[i][image[0].size()/2] = !image[i][image[0].size()/2];
        }
        return image;
    }
};