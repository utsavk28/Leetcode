class Solution {
public:
    int maxProduct(vector<string>& words) {
        int i,j,k,n=words.size();
        vector<vector<int>> v(n,vector<int>(26,0));
        for(i=0;i<n;i++) {
            vector<int> temp(26,0);
            for(auto it:words[i]) {
                v[i][it-'a']++;
            }
        }
        int ans = 0;
        for(i=0;i<n;i++) {
            for(j=0;j<i;j++) {
                bool flag = true;
                for(k=0;k<26;k++) {
                    if(v[i][k] != 0 && v[j][k] != 0) {
                        flag = false;
                        break;
                    }
                }
                k = words[i].size()*words[j].size();
                if(flag) {
                    // cout<<words[i]<<" "<<words[j]<<endl;
                    ans = max(ans,k);
                }
            }
        }
        
        return ans;
    }
};