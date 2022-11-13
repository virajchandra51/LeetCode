//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        for(auto it:x)
        {
            if(it=='[' || it=='{' || it=='(')
            s.push(it);
            else
            {
                if(s.empty()==true)
                return false;
                else
                {
                    if(it==']')
                    {
                        if(s.top()=='[')
                        {
                            s.pop();
                        }
                        else
                        return false;
                    }
                    if(it==')')
                    {
                        if(s.top()=='(')
                        {
                            s.pop();
                        }
                        else
                        return false;
                    }
                    if(it=='}')
                    {
                        if(s.top()=='{')
                        {
                            s.pop();
                        }
                        else
                        return false;
                    }
                }
            }
        }
        return s.empty()==true;
        // Your code here
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends