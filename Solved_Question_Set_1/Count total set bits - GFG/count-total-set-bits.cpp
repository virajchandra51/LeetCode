//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        int s = ceil(n/2.0);
        int nn = n;
        n>>=1;
        int j=4;
        int k=2;
        while(n>0)
        {
            s += ((nn/j)*k);
            int ns = nn - (nn/j)*j +1;
            ns-=k;
            if(ns>0)
            s+=ns;
            k*=2;
            j*=2;
            n>>=1;
        }
        return s;
        // Your logic here
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends