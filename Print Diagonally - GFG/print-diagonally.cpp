//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
	    vector<int> v;
	    for(int i=0;i<N;i++)
	    {
	        int ii = i ;
	        int j = 0;
	        while(ii>=0 && j<N)
	        {
	            v.push_back(A[j][ii]);
	            ii--;j++;
	        }
	    }
	    for(int i=1;i<N;i++)
	    {
	        int ii = i;
	        int j = N-1;
	        while(ii<N && j>=0)
	        {
	            v.push_back(A[ii][j]);
	            ii++;j--;
	        }
	    }
	    return v;
		// Your code goes here
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends