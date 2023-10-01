class Solution {
public:
    string toGoatLatin(string sentence) {
        string w=""; string ans=""; int k=1;
        sentence+=" ";
        for(auto it:sentence)
        {
            if(it!=' ')
                w+=it;
            else
            {
                if(w[0]=='a' || w[0]=='e' || w[0]=='i' || w[0]=='o' || w[0]=='u' || w[0]=='A' || w[0]=='E' || w[0]=='I' || w[0]=='O' || w[0]=='U')
                    ans+=(w+"ma");
                else
                    ans+=(w.substr(1,w.size()-1)+w[0]+"ma");
                for(int j=1;j<=k;j++)
                    ans+='a';
                k++;
                ans+=' ';
                w="";
            }
        }
        return ans.substr(0,ans.size()-1);
    }
};