class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> v(26,0);
        
        transform(licensePlate.begin(),licensePlate.end(),
                  licensePlate.begin(),::tolower);
        for(auto it: licensePlate)
        {
            if(it>='a' && it<='z')
                v[it-'a']++;
        }
            
        string s = ""; int cc = -1; int f=0;
        for(auto word:words){
            vector<int> w(26,0);
            for(auto it:word)
                w[it-'a']++;
            int c = 0;
            for(int i=0;i<26;i++)
                c+=(min(w[i],v[i]));
            cout<<c<<endl;
            if(c>=cc)
            {
                if(c==cc)
                {
                    if(f==1)
                    {
                        if(word.size()<s.size())
                        {s=word;cc=c;}
                    }
                    else
                    {
                        s=word;f=1;cc=c;
                    }
                }
                else
                {
                    s=word;
                    cc=c;
                    f=1;
                }
            }
            cout<<s<<endl;
            cout<<f<<endl;
        }
        return s;
    }
};