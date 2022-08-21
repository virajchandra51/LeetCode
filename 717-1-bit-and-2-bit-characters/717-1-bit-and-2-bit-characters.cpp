class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0;
        while(i<bits.size()-1)
        {
            if(bits[i]==0 && bits[i+1]==1)
                i++;
            else if(bits[i]==1 && bits[i+1]==0)
                i+=2;
            else if(bits[i]==1 && bits[i+1]==1)
                i+=2;
            else if(bits[i]==0 && bits[i+1]==0)
            {
                i++;
            }
        }
        if(i==bits.size())
            return false;
        else return true;
    }
};