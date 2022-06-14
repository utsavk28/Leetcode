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
        
        return util(1,n-2,nums,dp);
    }
};