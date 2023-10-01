class Solution {
public:
    int compareVersion(string v1, string v2) {
        vector<string> a,b;
        string w  = "";
        for(auto it:v1)
        {
            if(it!='.')
                w+=it;
            else
            {
                int i = 0;
                while(i<w.size()-1 && w[i]=='0') i++;
                w=w.substr(i);
                if(w.size()!=0) a.push_back(w); w="";
            }
        }
        int i = 0;
        while(i<w.size()-1 && w[i]=='0') i++;
        w=w.substr(i);  
        if(w.size()!=0) a.push_back(w);
        w="";
        for(auto it:v2)
        {
            if(it!='.')
                w+=it;
            else
            {
                int j = 0;
                while(j<w.size()-1 && w[j]=='0') j++;
                w=w.substr(j);
                if(w.size()!=0) b.push_back(w); w="";
            }
        }
        int j = 0;
        while(j<w.size()-1 && w[j]=='0') j++;
        w=w.substr(j);  
        if(w.size()!=0) b.push_back(w);
        i=0;
        j=0;
        for(auto it:a) cout<<it<<" ";
        cout<<endl;
        for(auto it:b) cout<<it<<" ";
        cout<<endl;
        while(i<a.size() && j<b.size())
        {
            if(stoi(a[i])>stoi(b[j])) return 1;
            if(stoi(a[i])<stoi(b[j])) return -1;
            i++;
            j++;
        }
        while(i<a.size())
        {
            if(a[i]>"0") return 1;
            i++;
        }
        while(j<b.size())
        {
            if(b[j]>"0") return -1;
            j++;
        }
        return 0;
    }
};