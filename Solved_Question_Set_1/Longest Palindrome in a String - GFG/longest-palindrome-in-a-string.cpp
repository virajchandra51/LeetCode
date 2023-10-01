//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

   public:
 

//checkPlaindrome
   vector<int> checkPalindrome(string &s, int i, int j){
       while(i>=0 && j<s.size() && s[i]==s[j]){
          i--;j++;
       }
       return {j-i-1,i+1,j-1};
   } 
   
   
   string longestPalin (string S) {
       // code here
       int n = S.length();
       string max_str="";
       vector<int> m = {INT_MIN,-1,-1};
       for(int i=0;i<n;i++){
           auto a = checkPalindrome(S,i,i);
           auto b = checkPalindrome(S,i,i+1);
           if(a[0]>m[0])
           {
            //   cout<<i<<endl;
               m[0] = a[0];
               m[1] = a[1];
               m[2] = a[2];
           }
           if(b[0]>m[0])
           {
            //   cout<<i<<" j"<<endl;
               m[0] = b[0];
               m[1] = b[1];
               m[2] = b[2];
           }
       }
    //   cout<<m[0]<<" "<<m[1]<<" "<<m[2]<<endl;
       return S.substr(m[1],m[0]);
   }

};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends