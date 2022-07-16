class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int i,j,k=0;
        int ans = 0;
        for(i=1;k<n;i++) {
            k += i;
            if((n-k)%i == 0) { 
                // cout<<i<<" ";
                ans++;
            }
        }
        // cout<<" | ";
        return ans;
    }
};