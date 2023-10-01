class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string w="";
        if(a>b)
        {
            int f = (a-1)/2;
            int bb = b-f;
            for(int i=1;i<=f;i++)
            {
                w+="aa";
                w+="b";
                if(bb>0)
                {
                    w+="b";
                    bb--;
                }
            }
            if(a%2)
                w+="a";
            else
                w+="aa";
            for(int i=1;i<=bb;i++)
                w+="b";
            
        }
        else if(a<b)
        {
            int f = (b-1)/2;
            int bb = a-f;
            for(int i=1;i<=f;i++)
            {
                w+="bb";
                w+="a";
                if(bb>0)
                {
                    w+="a";
                    bb--;
                }
            }
            if(b%2)
                w+="b";
            else
                w+="bb";
            for(int i=1;i<=bb;i++)
                w+="a";
        }
        else
        {
            for(int i=1;i<=(a-1)/2;i++)
                w+="aabb";
            if(a%2)
                w+="ab";
            else
                w+="aabb";
        }
        return w;
    }
};