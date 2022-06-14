class Solution {
public:
    int util(int i,int j,vector<int> &cuts,vector<vector<int>> &dp) {
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k=i;k<=j;k++) {
            ans = min(ans,util(i,k-1,cuts,dp)+util(k+1,j,cuts,dp)+(cuts[j+1]-cuts[i-1]));     
        }
        
        return dp[i][j]=ans;        
    }
    
    int minCost(int n, vector<int>& cuts) {
        int i,j,k=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>> dp(k+2,vector<int>(k+2,-1));
        
        return util(1,k,cuts,dp);
    }
};