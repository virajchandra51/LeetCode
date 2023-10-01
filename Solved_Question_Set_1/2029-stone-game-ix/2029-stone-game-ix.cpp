class Solution {
public:
    
    bool stoneGameIX(vector<int>& stones) {
        int z=0,o=0,t=0;
        for(int i=0;i<stones.size();i++)
        {
            if(stones[i]%3==0)
                z++;
            else if(stones[i]%3==1)
                o++;
            else
                t++;
        }
        if(z==0)
        {
            if(o>0 && t>0)
                return true;
            else
                return false;
        }
        else if(z>0 && z&1)
        { 
            if(o==t)
                return false;
            if(o>0 && t>0)
            {
                if(abs(t-o)>=3)
                    return true;
                else
                    return false;
            }
            else
            {
                if(o==0)
                {
                    if(t>=3)
                        return true;
                    else
                        return false;
                }
                else if(t==0)
                {
                    if(o>=3)
                        return true;
                    else
                        return false;
                }
            }
        }
        else
        {
                if(o>0 && t>0)
                    return true;
                else
                    return false;
            
        }
        // 2 0 2 2
        // 
        // 1 2 0 2 0
        // 
        // 0 2 1 1 2 0 2 2 0
        // 2 2 2 2 1 1 0 0 0
        // 2 0 0 0 2 1 2 1 2 
        return false;
    }
};