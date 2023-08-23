class Solution {
public:
    bool canMeasureWater(int x, int y, int targetCapacity) {
        int operations[4]= {x,-x,y,-y};
        queue<int>q;
        q.push(0);
        vector<int> visited(x+y+1,0);
        visited[0]=1;
        while(!q.empty()){
           int water=q.front();
           q.pop();
           if(water==targetCapacity)
               return true;
           for(int i=0;i<4;i++){
               int newwater=water+operations[i];
               if(newwater>=0 && newwater<=(x+y) && visited[newwater]==0)                {
                   visited[newwater]=1;
                   q.push(newwater);
               }
           }
        }
        return false;
    }
};