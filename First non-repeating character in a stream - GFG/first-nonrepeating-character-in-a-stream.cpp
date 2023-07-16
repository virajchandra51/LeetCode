//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    map<char,int> m;
		    m[A[0]]++;
		    string a = "";
		    a+=A[0];
		    char ch = A[0];
		    int j = 0;
		    for(int i = 1;i<A.size();i++)
		    {
		        m[A[i]]++;
		        if(m[A[i]]==1 && ch=='#') ch=A[i]; 
		        if(m[ch]==1)
		        {
		            a+=ch;
		        }
		        else
		        {
		            while(j<i && m[A[j]]!=1)
		            {
		                j++;
		            }
		            if(j==i)
		            {
		                ch='#';
		                a+=ch;
		            }
		            else
		            {
		                ch=A[j];
		                a+=ch;
		            }
		        }
		    }
		    return a;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends