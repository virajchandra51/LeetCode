class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        vector<vector<long long>> t(n+1, vector<long long>(n+1, 0));
        //t[i][j] = Maximum distance reached if I stopped at 'j' fuelStops from total of 'i' fuleStops
        //i.e. j <= i
        
        //If j = 0, i.e. I did not use any fuelStops, Then maximum I can reach is 'startFuel' which I had initially
        
        //So, initialize the dp array with this information
        for(int i = 0; i<n+1; i++) {
            t[i][0] = startFuel;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=i;j++)
            {
                //dont refuel
                t[i][j] = t[i-1][j];
                //i refuel
                if(t[i-1][j-1] >= stations[i-1][0]) {
                    t[i][j] = max(t[i][j], t[i-1][j-1] + stations[i-1][1]);
                }
            }
        }
        
        cout<<endl;
         for(int j = 0; j<n+1; j++) {
            if(t[n][j] >= target)
                return j;
        }
        
        //You could never reach target, so return -1
        return -1;
    }
};