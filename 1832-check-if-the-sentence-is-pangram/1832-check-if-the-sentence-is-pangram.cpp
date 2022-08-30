class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int> mp;
        for(auto it:sentence)
            mp[it]++;
        return mp.size()==26;
    }
};