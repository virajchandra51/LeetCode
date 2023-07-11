//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

// } Driver Code Ends
class Solution{
    public:
    //You need to complete this fucntion
    long long po(long long x, long long y, long long p)
    {
     
        // Initialize answer
        long long res = 1;
        // Check till the number becomes zero
        while (y > 0) {
     
            // If y is odd, multiply x with result
            if (y % 2 == 1)
                res = (res * x)% p;
     
            // y = y/2
            y = y >> 1;
     
            // Change x to x^2
            x = (x * x)%p;
        }
        return res%p;
    }
    long long power(int N,int R)
    {
       return po(N,R,1e9+7);
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends