//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
// Driver program to test above function

// } Driver Code Ends
class Solution{
  public:
    /*you are required to complete this method*/
    int convertFive(int n)
    {
        int ans=0;
        while(n>0)
        {
            if(n%10==0)
            ans=(ans*10+5);
            else
            ans=(ans*10+n%10);
            n/=10;
        }
        int mainans=0;
        while(ans>0)
        {
            mainans=(mainans*10+ans%10);
            ans/=10;
        }
        return mainans;
    //Your code here
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	Solution obj;
    	cout<<obj.convertFive(n)<<endl;
    }
}
// } Driver Code Ends