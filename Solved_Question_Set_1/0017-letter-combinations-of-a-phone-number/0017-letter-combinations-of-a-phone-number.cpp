class Solution {
public:
    vector<string> letterCombinations(string d) {
        vector<vector<string>> v;
        v.push_back({"a","b","c"});
        v.push_back({"d","e","f"});
        v.push_back({"g","h","i"});
        v.push_back({"j","k","l"});
        v.push_back({"m","n","o"});
        v.push_back({"p","q","r","s"});
        v.push_back({"t","u","v"});
        v.push_back({"w","x","y","z"});
        int n = d.size(); vector<string> a;
        if(n==0)
            return {};
        else if(n==1)
        {
            for(int i=0;i<v[d[0]-50].size();i++)
            {
                a.push_back((v[d[0]-50][i]));
            }
        }
        else if(n==2)
        {
            string s="";
            for(int i=0;i<v[d[0]-50].size();i++)
            {
                for(int j=0;j<v[d[1]-50].size();j++)
                {
                    s+=v[d[0]-50][i];
                    s+=v[d[1]-50][j];
                    a.push_back(s);
                    s="";
                }
            }
        }
        else if(n==3)
        {
            string s="";
            for(int i=0;i<v[d[0]-50].size();i++)
            {
                for(int j=0;j<v[d[1]-50].size();j++)
                {
                    for(int k=0;k<v[d[2]-50].size();k++)
                    {
                        s+=v[d[0]-50][i];
                        s+=v[d[1]-50][j];
                        s+=v[d[2]-50][k];
                        a.push_back(s);
                        s="";
                    }
                }
            }
        }
        else 
        {
            string s="";
            for(int i=0;i<v[d[0]-50].size();i++)
            {
                for(int j=0;j<v[d[1]-50].size();j++)
                {
                    for(int k=0;k<v[d[2]-50].size();k++)
                    {
                        for(int l=0;l<v[d[3]-50].size();l++)
                        {
                            s+=v[d[0]-50][i];
                            s+=v[d[1]-50][j];
                            s+=v[d[2]-50][k];
                            s+=v[d[3]-50][l];
                            a.push_back(s);
                            s="";
                        }
                    }
                }
            }
        }
        return a;
    }
};