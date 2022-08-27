class Solution {
public:
    string removeDigit(string number, char digit) {
         int n=number.size();
        string res=" ";
        for(int i=0;i<number.size();i++)
        {
            string temp;
           if(number[i]==digit)
           {
            temp=number.substr(0,i)+number.substr(i+1);
               res=max(res,temp);
           }
            
        }

        return res;
    
    }
};