// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int util(int i,int n,int k,vector<int> &nums,vector<int> &dp) {
        if(i == n) return -1;
        if(dp[i] != -1) return dp[i];
        
        int ans=INT_MAX,j,curr=0;
        for(j=i;j<n;j++) {
            curr += (nums[j]+1);
            if(curr-1 > k) break;
            
            int sum = util(j+1,n,k,nums,dp);
            if(sum == -1) {
                ans = 0; 
            }
            else {
                ans = min(ans,sum+(int)pow(k-curr+1,2));
            }
        }
        
        return dp[i]=ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int i,j,n=nums.size();
        vector<int> dp(n+1,-1);
        return util(0,n,k,nums,dp);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends