class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& i) {
        sort(i.begin(),i.end(),[](vector<int> &a, vector<int> &b) {return a[1]<b[1];});
        vector<int> prev= i[0];
        int ans = -1;
		for(vector<int> it: i) {
			if(prev[1]>it[0]) {
				ans++;                //we dont update previous, because i[1] will be grater then prev[1]
			}else prev=it;           // we want the end point to be minimum
		}
		return ans; 
    }
};