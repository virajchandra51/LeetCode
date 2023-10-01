//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    bool isPrime(int n){

        if(n == 1)

            return false;

            

        int i, cnt = 0;

        for(i=1; i*i <= n; i++){

            if(n%i == 0)

                cnt++;

        }

        if(cnt == 1)

            return true;

        else return false;

    }

    string isSumOfTwo(int N){

        // code here

        if(N < 4)

            return "No";

        

        if(N%2 == 0) // GoldBack's Conjecture

            return "Yes";

        else{

            if(isPrime(N-2))

                return "Yes";

            else return "No";

        }

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends