class Solution {
public:
    string reversePrefix(string word, char ch) {
        int id=-1;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]==ch)
            {
                id=i;break;
            }
        }
        if(id!=-1)
        {
            string s = word.substr(0,id+1);
            reverse(s.begin(),s.end());
            word=s+word.substr(id+1);
        }
        return word;
    }
};