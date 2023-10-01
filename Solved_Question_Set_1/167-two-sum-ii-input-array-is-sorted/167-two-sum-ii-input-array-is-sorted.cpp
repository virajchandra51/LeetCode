class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int l=0,r=num.size()-1;
        vector<int> v;
        while(l<=r)
        {
            if((num[l]+num[r])==target)
            {
                v.push_back(l+1);
                v.push_back(r+1);break;
            }
            else if((num[l]+num[r])<target)
            l++;
            else
            r--;
        }
        return v;
    }
};