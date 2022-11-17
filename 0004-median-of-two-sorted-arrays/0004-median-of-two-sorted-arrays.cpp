class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        if(n1.size()>n2.size()) return findMedianSortedArrays(n2,n1);
        int l1 = n1.size();
        int l2 = n2.size();
        int l = 0, h = l1;
        while(l<=h)
        {
            int cut1 = (l+h)>>1;
            int cut2 = (l1+l2+1)/2-cut1;
            int left1 = cut1==0 ? INT_MIN: n1[cut1-1];
            int left2 = cut2==0 ? INT_MIN: n2[cut2-1];
            int right1 = cut1==l1 ? INT_MAX: n1[cut1];
            int right2 = cut2==l2 ? INT_MAX: n2[cut2];
            
            if(left1<=right2 && left2<=right1)
            {
                if(!((l1+l2)&1))
                    return (max(left1,left2)+min(right1,right2))/2.0;
                else
                    return max(left1,left2);
            }
            else if(left1>right2)
                h=cut1-1;
            else
                l=cut1+1;
        }
        return 0.0;
    }
};