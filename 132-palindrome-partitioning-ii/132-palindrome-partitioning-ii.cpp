class Solution {
public:
    bool check(string &s) {
        int i=0,j=s.size()-1;
        while(i<j) {
            if(s[i] == s[j]) {
                i++,j--;
            }
            else return false;
        }
        return true;
    }
    
    int util(int i,int n,string &s,vector<int> &dp) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        
        string temp="";
        int j,k,cost = INT_MAX;
        for(j=i;j<n;j++) {
            temp += s[j];
            if(check(temp)) {
                cost = min(cost,1+util(j+1,n,s,dp));
            }
        }
        
        return dp[i]=cost;
    }
    
    int minCut(string s) {
        int i,j,k,n=s.size();
        vector<int> dp(n+1,0);
        // int ans = util(0,n,s,dp)-1;
        
        for(i=n-1;i>=0;i--) {
            string temp = "";
            dp[i] = INT_MAX-1;
            for(j=i;j<n;j++) {
                temp += s[j];
                if(check(temp)) {
                    dp[i] = min(dp[j+1]+1,dp[i]);
                }
            }
        }
        
        return dp[0]-1;
    }
};