class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ch = '?';
        for(auto it:letters)
        {
            if(it>target)
            {
                ch=it;break;
            }
        }
        if(ch=='?')
            ch=letters[0];
        return ch;
    }
};