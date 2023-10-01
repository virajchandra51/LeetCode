class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        long long temp = num_people;
        long long s = (temp)*(temp+1)/2;
        long long k=0,c=0;
        while(true)
        {
            if((k*temp*temp+s)<=candies)
            {
                c++;candies-=(k*temp*temp+s);
                k++;
            }
            else
                break;
        }
        vector<int> ans(num_people);
        if(c>0)
        {
            for(int i=0;i<num_people;i++)
            {
                ans[i] = (i+1)*c+num_people*(c-1)*c/2;
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            if(candies>=(c*num_people+(i+1)))
            {ans[i]+=(c*num_people+(i+1));candies-=(c*num_people+(i+1));}
            else
            {
                ans[i]+=candies;break;
            }
        }
        return ans;
    }
};