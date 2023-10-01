class Solution {
public:
    int countVowelSubstrings(string word) {
        int count = 0;
    for(int i=0;i<word.size();i++) {
        set<char> s1 = {'a', 'e', 'i', 'o', 'u'};
        set<char> s2;
        for(int j=i;j<word.size();j++) {
            if(s1.count(word[j]) == 0)
                break;
            s2.insert(word[j]);
            if(s1 == s2)
                count++;
        }
    }
    return count;
    }
};