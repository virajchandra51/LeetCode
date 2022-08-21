class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<char,string> mp({{'a',".-"},{'b',"-..."},{'c',"-.-."},{'d',"-.."},{'e',"."},{'f',"..-."},{'g',"--."},{'h',"...."},{'i',".."},{'j',".---"},{'k',"-.-"},{'l',".-.."},{'m',"--"},{'n',"-."},{'o',"---"},{'p',".--."},{'q',"--.-"},{'r',".-."},{'s',"..."},{'t',"-"},{'u',"..-"},{'v',"...-"},{'w',".--"},{'x',"-..-"},{'y',"-.--"},{'z',"--.."}});
            set<string> s;
        for(auto it:words)
        {
            string w="";
            for(int i=0;i<it.size();i++)
            {
                w+=mp[it[i]];
            }
            s.insert(w);
        }
        return s.size();
    }
};