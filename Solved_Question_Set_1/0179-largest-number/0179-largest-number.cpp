class Solution {
public:
    static bool comp(int &a, int &b)
    {
        string aa = to_string(a);
        string bb = to_string(b);
        string aaa = aa+bb;
        string bbb = bb+aa;
        return aaa>bbb;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        string a = "";
        int i = 0;
        while(i<nums.size() && nums[i]==0) i++;
        if(i==nums.size()) return "0";
        while(i<nums.size())
        {
            a+=(to_string(nums[i]));
            i++;
        }
        return a;
    }
};