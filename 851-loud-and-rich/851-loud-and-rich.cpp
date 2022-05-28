class Solution {
public:
    void DFSUtil(int i,int &fans,int &qp,vector<vector<int>> &v,vector<bool> &vis, vector<int> &quiet) {
        if(vis[i]) return;
        vis[i]=true;
        if(fans > quiet[i]) {
            qp = i;
        }
        fans = min(fans,quiet[i]);
        
        for(auto it:v[i]) {
            DFSUtil(it,fans,qp,v,vis,quiet);
        }
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        // vector<int>
        int i,j,k,n=quiet.size();
        vector<vector<int>> v(n);
        
        for(auto it:richer) {
            v[it[1]].push_back(it[0]);
        }
        
        vector<int> ans(n);
        for(i=0;i<n;i++) {
            int fans = quiet[i],qp=i;
            vector<bool> vis(n,false);
            DFSUtil(i,fans,qp,v,vis,quiet);
            ans[i] = qp;
        }
        
        return ans;
    }
};