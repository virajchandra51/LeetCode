class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3)
            return false;
        int x = max_element(arr.begin(),arr.end())-arr.begin();
        if(x==0 || x==arr.size()-1)
            return false;
        for(int i=0;i<x;i++)
        {
            if(arr[i+1]<=arr[i])
                return false;
        }
        for(int i=x;i<arr.size()-1;i++)
        {
            if(arr[i+1]>=arr[i])
                return false;
        }
        return true;
    }
};