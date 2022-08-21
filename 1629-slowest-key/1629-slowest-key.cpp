class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int> v(releaseTimes.size());
        v[0] = releaseTimes[0];
        for(int i=1;i<releaseTimes.size();i++)
        v[i] = releaseTimes[i]-releaseTimes[i-1]; 
        for(auto it: v)
            cout<<it<<" ";
        cout<<endl;
        char ch = '1'; int f=-1;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>f)
            {
                f=v[i];
                ch=keysPressed[i];
            }
            if(v[i]==f && keysPressed[i]>ch)
            {
                ch=keysPressed[i];
            }
        }
        
        return ch;
    }
};