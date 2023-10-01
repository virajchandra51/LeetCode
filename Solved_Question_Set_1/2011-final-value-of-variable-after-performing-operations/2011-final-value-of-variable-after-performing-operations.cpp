class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto it:operations)
        {
            if(it[0]=='-' || it[2]=='-')
                x--;
            else
                x++;
        }
        return x;
    }
};