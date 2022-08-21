class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isPresent = false;
        set<string> s;
        for(auto word: wordList)
        {
            if(word.compare(endWord)==0)
                isPresent = true;
            s.insert(word);
        }
        if(!isPresent)
            return 0;
        queue<string> q;
        int depth = 0;
        q.push(beginWord);
        while(!q.empty())
        {
            depth+=1;
            int lsize = q.size();
            while(lsize--)
            {
                string curr = q.front();
                q.pop();
                for(int i=0;i<curr.length();i++)
                {
                    string temp = curr;
                    for(char ch ='a';ch<='z';ch++)
                    {
                        temp[i]=ch;
                        if(temp.compare(curr)==0)
                            continue;
                        if(temp.compare(endWord)==0)
                            return depth+1;
                        if(s.find(temp)!=s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};