class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();i++)
        {
            int c=0; int sum=0;
            while(c<nums.size())
            {
                if(sum+nums[c]<=queries[i])
                sum+=nums[c];
                else
                    break;
                c++;
            }
            queries[i]=c;
        }
        return queries;
    }
};