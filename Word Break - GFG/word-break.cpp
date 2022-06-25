// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    unordered_map<string,bool> mp;
    
    bool util(int i,int n,string &A,vector<bool> &dp) {
        if(i == n) return true;
        if(dp[i]) return dp[i];
        
        string acc = "";
        bool ans = false;
        for(int j=i;j<n;j++) {
            acc += A[j];
            if(mp[acc]) ans = ans || util(j+1,n,A,dp);
        }
        
        return dp[i]=ans;
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        mp.clear();
        for(auto it:B) mp[it]=true;
        int i,j,k,n=A.size();
        vector<bool> dp(n+1,false);
        return util(0,A.size(),A,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends