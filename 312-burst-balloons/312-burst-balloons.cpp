class Solution {
public:
    int util(int i,int j,vector<int> &nums,vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MIN;
        for(int k = i;k<=j;k++) {
            ans = max(ans,util(i,k-1,nums,dp)+util(k+1,j,nums,dp)+nums[k]*nums[i-1]*nums[j+1]);
        }
        
        return dp[i][j]=ans;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int i,j,k,n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(i=n-2;i>=1;i--) {
            for(j=1;j<=n-2;j++) {
                if(i>j)dp[i][j]=0;
                else {
                    dp[i][j] = INT_MIN;
                    for(k=i;k<=j;k++) {
                        dp[i][j] = max(dp[i][j],dp[i][k-1]+dp[k+1][j]+nums[k]*nums[i-1]*nums[j+1]);
                    }
                }
            }
        }
        return dp[1][n-2]+2;
        // return util(1,n-2,nums,dp);
    }
};