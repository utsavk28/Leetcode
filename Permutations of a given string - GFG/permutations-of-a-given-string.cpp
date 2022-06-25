// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	   map<string,bool> mp;
	    void util(int i,int n,string &S) {
	        if(i == n) {
	            mp[S]=true;
	            return;
	        }
	        
	        for(int j=i;j<n;j++) {
	            swap(S[i],S[j]);
	            util(i+1,n,S);
	            swap(S[i],S[j]);
	        }
	    }

		vector<string>find_permutation(string S)
		{
		    // Code here there
		    mp.clear();
		    sort(S.begin(),S.end());
		    util(0,S.size(),S);
	        vector<string> ans;
	        for(auto it:mp) ans.push_back(it.first);
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends