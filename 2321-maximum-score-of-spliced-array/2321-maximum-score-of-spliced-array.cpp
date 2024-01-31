class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> diff(n);
        // 30 0 -40 85 -20 0
        for(int i=0;i<n;i++)
            diff[i] = nums2[i]-nums1[i];
        int sum1 = 0;
        int sum2 = 0;
        for(auto it:nums1) sum1+=it;
        for(auto it:nums2) sum2+=it;
        int answer = max(sum1,sum2);
        int sumKadane = 0;
        int c = 0;
        for(int i=0;i<n;i++)
        {
            sumKadane+=diff[i];
            c=max(c,sumKadane);
            if(sumKadane>0)
            {
                answer = max(answer,sum1+c);
            }
            else sumKadane = 0;
        }
        sumKadane = 0;
        c=0;
        for(auto &it:diff) it*=-1;
        for(int i=0;i<n;i++)
        {
            sumKadane+=diff[i];
            c=max(c,sumKadane);
            if(sumKadane>0)
            {
                answer = max(answer,sum2+c);
            }
            else sumKadane = 0;
        }
        return answer;
    }
};