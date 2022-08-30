class Solution {
public:
    bool squareIsWhite(string coordinates) {
        if(coordinates[0]+coordinates[1]&1)
            return true;
        return false;
    }
};