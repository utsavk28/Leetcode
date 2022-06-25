// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int i,j,k,n=s.size();
	    i=n-1,j=n-2;
	    while(j>=0) {
	        int count = 0;
	        while(j>=0 && s[i] == s[j]) {
	            i--,j--;
	            count++;
	        }
	        
	        if(j == -1) return count;
	        i=n-1;
	        if(count == 0) j--;
	    }
	    
	    return 0;
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends