class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int c = 0;
        for(auto it:hours) if(it>=target)c++;
        return c;
    }
};