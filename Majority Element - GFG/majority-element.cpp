//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int candidate = a[0];
        int s=1;
        for(int i=1;i<size;i++)
        {
            if(a[i]==candidate) s++;
            else s--;
            if(s<0) {candidate = a[i]; s=0;}
        }
        int c=0;
        for(int i=0;i<size;i++)
        {
            if(a[i]==candidate) c++;
        }
        if(c<=(size/2)) return -1;
        return candidate;
        // your code here
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends