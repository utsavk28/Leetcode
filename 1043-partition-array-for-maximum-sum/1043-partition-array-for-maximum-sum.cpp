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
        vector<int> dp(n+1,0);
        for(i=n-1;i>=0;i--) {
            int maxi=INT_MIN,ans=INT_MIN;
            for(j=0;j<k;j++) {
                int temp = j+i;
                if(temp>=n) break;
                maxi= max(maxi,arr[temp]);
                ans = max(ans,maxi*(j+1)+dp[temp+1]);
            }
            dp[i] = ans;
        }
        
        // for(auto it:dp) cout<<it<<" ";
        // cout<<endl;
        
        return dp[0];
        // return util(arr,k,0,n,dp);
    }
};