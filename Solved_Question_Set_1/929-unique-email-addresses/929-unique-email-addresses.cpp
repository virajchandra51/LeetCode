class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for(auto it:emails){
            string l = "", d="";
            for(int i=0;i<it.size();i++)
            {
                if(it[i]=='@')
                {
                    l=it.substr(0,i);
                    d=it.substr(i+1,it.size()-i-1); break;
                }
            }
            cout<<l<<" "<<d<<endl;
            string rl = "";
            for(int i=0;i<l.size();i++)
            {
                if(l[i]=='.')
                    continue;
                if(l[i]=='+')
                    break;
                rl+=l[i];
            }
            s.insert(rl+"@"+d);
        }
        return s.size();
    }
};