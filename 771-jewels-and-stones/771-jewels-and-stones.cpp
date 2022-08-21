class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s;
        for(auto it:jewels)
            s.insert(it);
        int c=0;
        for(auto it:stones)
        {
            if(s.find(it)!=s.end())
                c++;
        }
        return c;
    }
};