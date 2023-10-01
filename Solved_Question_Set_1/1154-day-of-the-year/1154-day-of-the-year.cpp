class Solution {
public:
    int dayOfYear(string date) {
        vector<int> v = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(stoi(date.substr(0,4))%4==0 && stoi(date.substr(0,4))%100!=0)
            v[1]++;
        if(stoi(date.substr(0,4))%400==0)
            v[1]++;
        int m = stoi(date.substr(5,2));
        int d = stoi(date.substr(8,2));
        int ans=0;
        for(int i=0;i<m-1;i++)
            ans+=v[i];
        ans+=d;
        return ans;
    }
};