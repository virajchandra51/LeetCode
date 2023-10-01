//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int a = 0;
	    int n = s.size();
	    if(s[n-1]=='1') a++;
	    int pos=1;
	    for(int i=n-2;i>=0;i--)
	    {
	        char ch = s[i];
	        if(ch=='0') {pos++;continue;}
	        if(pos&1)
	        {
	            a+=2;
	        }
	        else a+=4;
	        pos++;
	    }
	    return a%3==0;
	}
	
	
};


//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends