class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long i,j,k=0,n=beans.size();
        long long ans = INT_MAX,sum=0;
        for(i=0;i<n;i++) {
            sum += beans[i];
        }
        ans = sum;
        for(i=0;i<n;i++) {
            ans = min(ans,k+(sum-beans[i]*(n-i)));
            sum -= beans[i];
            k += beans[i];
        }
        
        return ans;
    }
};