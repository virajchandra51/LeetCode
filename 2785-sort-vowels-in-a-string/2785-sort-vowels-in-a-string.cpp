class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        for(auto it:s)
        {
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u' || it=='A' || it=='E' || it=='I' || it=='O' || it=='U')
                v.push_back(it);
        }
        sort(v.begin(),v.end());
        int i = 0;
        for(auto &it:s)
        {
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u' || it=='A' || it=='E' || it=='I' || it=='O' || it=='U')
                it=v[i++];
        }
        return s;
    }
};