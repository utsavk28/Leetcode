// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int util(int i,int j,int arr[],vector<vector<int>> &dp) {
        if(i == j) {
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int k,ans=INT_MAX,temp;
        for(k=i;k<j;k++) {
            temp = arr[i]*arr[k+1]*arr[j+1]+util(i,k,arr,dp)+util(k+1,j,arr,dp);
            ans = min(ans,temp);
            // cout<<temp<<" ";
        }
        
        return dp[i][j] = ans;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return util(0,N-2,arr,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends