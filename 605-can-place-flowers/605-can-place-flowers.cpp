class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> v;
        v.push_back(-1);
        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i])
                v.push_back(i);
        }
        v.push_back(flowerbed.size());
        if(v.size()==2)
        {
            if(flowerbed.size()==1 && n==1)
                return true;
            if(ceil(flowerbed.size()/2.0) >=n)
                return true;
            else
                return false;
        }
        int c=0;
        for(int i=0;i<v.size()-1;i++)
        {
            if(i==0)
            {
                if(v[i+1]-v[i]>=3)
                {
                    c+=((v[i+1])/2);
                }
            }
            else if(i==(v.size()-2))
            {
                if(v[i+1]-v[i]>=3)
                {
                    c+=((v[i+1]-v[i]-1)/2);
                }
            }
            else if(v[i+1]-v[i]>=3)
            {
                c+=((v[i+1]-v[i]-1-1)/2);   
            }
            
           
        }
        if(c>=n)
            return true;
        else
            return false;
        
    }
};