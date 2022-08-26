class Solution {
public:
    string defangIPaddr(string address) {
        string w="";
        for(auto it:address)
        {
            if(it=='.')
                w+="[.]";
            else
                w+=it;
        }
        return w;
    }
};