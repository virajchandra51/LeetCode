class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> v;
        for(auto it:arr)
        {
            if(it!=0)
                v.push_back(it);
            else
            {
                v.push_back(0);
                v.push_back(0);
            }
            
        }
        for(int i=0;i<arr.size();i++)
            arr[i]=v[i];
    }
};