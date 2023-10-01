class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int id =-1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>=nums[i+1])
            {
                id=i;break;
            }
        }
        if(id!=-1)
        {
            vector<int> v,vv;
            for(int i=0;i<nums.size();i++)
            {
                if(i!=id)
                    v.push_back(nums[i]);
            }
            for(int i=0;i<nums.size();i++)
            {
                if(i!=(id+1))
                    vv.push_back(nums[i]);
            }
            int f=1,a=1;
            for(int i=0;i<v.size()-1;i++)
            {
                if(v[i]>=v[i+1])
                {
                    f=0;break;
                }
            }
            for(int i=0;i<vv.size()-1;i++)
            {
                if(vv[i]>=vv[i+1])
                {
                    a=0;break;
                }
            }
            if(f==0 && a==0)
                return false;
            return true;
        }
    return true;
    }
};