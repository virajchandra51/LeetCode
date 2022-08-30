class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> st;
        string prev="";
        for(int i=0;i<word.size();i++)
        {
            if(!isdigit(word[i])){
                if(prev!=""){
                    st.insert(prev);
                    prev="";
                }
            }
            else{
                //a digit
                if(prev=="" && word[i]=='0')
                {
                    //starting with 0
                    if(i+1<word.size() && isdigit(word[i+1]))
                        continue;
                    else{
                        st.insert("0");
                        prev.push_back('0');
                    }
                }
                else
                    prev.push_back(word[i]);
            }
        }
        if(prev!="")
            st.insert(prev);
        return st.size();
    }
};