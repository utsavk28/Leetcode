class Solution {
public:
    int util(vector<int> &arr,int k,int startIdx,int n,vector<int> &dp) {
        if(startIdx >= n) return 0;
        if(dp[startIdx] != -1) return dp[startIdx];

        int i,j;
        int ans = 0,maxi = 0;
        for(j=0;j<k;j++) {
            i = j+startIdx;
            if(i>=n) break;
            
            maxi = max(maxi,arr[i]);
            ans = max(ans,maxi*(j+1)+util(arr,k,i+1,n,dp));
        }

        return dp[startIdx]=ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int i,j,n=arr.size();
        vector<int> dp(n,-1);
        return util(arr,k,0,n,dp);
    }
};