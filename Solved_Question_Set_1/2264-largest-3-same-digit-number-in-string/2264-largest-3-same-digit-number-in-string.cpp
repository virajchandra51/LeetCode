class Solution {
public:
    string largestGoodInteger(string num) {
        string w="";
        for(int i=0;i<num.size()-2;i++)
        {
            if(num[i]==num[i+1] && num[i]==num[i+2] && (w.size()==0 || (num[i]-48)>                 (w[0]-48)))
            {
                w="";
                w+=num[i];
                w+=num[i+1];
                w+=num[i+2];
            }
        }
        return w;
    }
};