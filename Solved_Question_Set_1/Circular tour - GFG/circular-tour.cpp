//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump arr[],int n)
    {
        int s1=0;
        int s2=0;
        for(int i=0;i<n;i++)
        {
            s1+=arr[i].petrol;
            s2+=arr[i].distance;
        }
        if(s1<s2) return -1;
        vector<int> diff(n,0);
        for(int i=0;i<n;i++)
        diff[i] = arr[i].petrol-arr[i].distance;
        int start=0;
        int total=0;
        for(int i=0;i<n;i++)
        {
            total+=diff[i];
            if(total<0)
            {
                total=0;
                start=i+1;
            }
        }
        return start;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends