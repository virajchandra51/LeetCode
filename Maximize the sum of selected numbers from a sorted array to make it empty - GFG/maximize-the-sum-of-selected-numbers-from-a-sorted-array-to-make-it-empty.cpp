//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        multiset<int,greater<int>> m;
        for(int i=0;i<n;i++)
        {
            m.insert(a[i]);
        }
        
        int sum =0;
        while(m.size()>0)
        {
            int ma = *m.begin();
            sum+=ma;
            
            if(m.find(ma-1)!=m.end())
            {
                auto it = m.find(ma-1);
                m.erase(it);
            }
            
            m.erase(m.begin());
        }
        return sum;
        // Complete the function
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends