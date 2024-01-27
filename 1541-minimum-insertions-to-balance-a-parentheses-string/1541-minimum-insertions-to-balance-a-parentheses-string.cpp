class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int count = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push(s[i]); // If I have a '(' store it
            else
            {
                // if I find two consecutive ))
                if(i+1<s.size() && s[i+1]==')')
                {
                    // if for those )) I have a ( in stack no need to increase count
                    if(st.size()>0)
                    {
                        st.pop();
                    }
                    // if I dont have ( in stack means I need to insert a ( in the string for the two )) I have at s[i] & s[i+1]
                    else
                    {
                        count++;
                    }
                    // since I know s[i] & s[i+1] have ) kept I can jump two indexes forward to i+2
                    i++;
                }
                // if s[i+1] is not equal to )
                else 
                {
                    count++; // I would have to insert a ) to pair up with the s[i] character so that I get two consecutive ))
                    // if now for the two consecutive )) I have a ( in stack i pop it out
                    if(st.size()>0)
                    {
                        st.pop();
                    }
                    // If I dont have a (  in stack that means again I need to insert (  in string 
                    else
                    {
                        count++;
                    }
                }
            }
        }
        // if coming out of loop there are still some ( left in stack which did not get their pairs of )) , then I add them to the answer too
        count+=(2*st.size());
        return count;
    }
};