class Solution {
public:
    void performFill(vector<vector<int>>& image,int sr, int sc, int& color, int &initialColor)
    {
        if(image[sr][sc] != initialColor)
            return;
        else
        {
            image[sr][sc] = color;
            if(sr-1>=0)
                performFill(image,sr-1,sc,color,initialColor);
            if(sr+1<image.size())
                performFill(image,sr+1,sc,color,initialColor);
            if(sc-1>=0)
                performFill(image,sr,sc-1,color,initialColor);
            if(sc+1<image[0].size())
                performFill(image,sr,sc+1,color,initialColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
            return image;
        int initialColor = image[sr][sc];
        performFill(image,sr,sc,color,initialColor);
        return image;
    }
};