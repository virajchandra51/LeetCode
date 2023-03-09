class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& i) {
        sort(i.begin(),i.end(),[](vector<int> &a, vector<int> &b) {return a[1]<b[1];});
        for(auto it:i)
            cout<<it[0]<<" "<<it[1]<<endl;
        
        int n=i.size(), ans=-1, prev=i[0][1];
        for(int j=0;j<n;j++){
            if(i[j][0]<prev){
                ans++;
            }
            else prev=i[j][1];
        }return ans;
    }
};