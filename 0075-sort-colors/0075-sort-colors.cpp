class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> hash(3,0);
        for(int i=0;i<nums.size();i++)
            hash[nums[i]]++;
    for(int i=0;i<hash.size();i++)
             cout<<hash[i]<<endl;
             for(int i=0;i<hash[0];i++)
                 nums[i]=0;
        for(int i=0;i<nums.size();i++)
             cout<<nums[i];
        cout<<endl;
                 for(int i=hash[0];i<(hash[1]+hash[0]);i++)
                 nums[i]=1;
        for(int i=0;i<nums.size();i++)
             cout<<nums[i];
        cout<<endl;
                 for(int i=hash[1]+hash[0];i<(hash[2]+hash[0]+hash[1]);i++)
                 nums[i]=2;
        for(int i=0;i<nums.size();i++)
             cout<<nums[i];
        cout<<endl;
             
        for(int i=0;i<hash.size();i++)
             cout<<hash[i];
    return;
    }
};