class Solution {
public:
    int minTimeToType(string word) {
        int time=0;
        char ch = 'a';
        for(int i=0;i<word.size();i++)
        {
            if(word[i]>ch)
            time+=(min(abs((word[i]-ch)),abs(26-(word[i]-ch))));
            else
            time+=(min(abs((ch-word[i])),abs(26-(ch-word[i]))));
            time++;
            ch=word[i];
        }
        return time;
    }
};