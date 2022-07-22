class Solution {
public:
    // int recur(int i, int j, vector<int> &cuts,vector<vector<int>> &dp){
    //     if(i>j){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int mini=1e9;
    //     for(int ind=i;ind<=j;ind++){
    //         int cut=cuts[j+1]-cuts[i-1]+recur(i,ind-1,cuts,dp)+recur(ind+1,j,cuts,dp);
    //         mini=min(mini,cut);
    //     }
    //     return dp[i][j]=mini;
    // }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+2,vector(c+2,0));
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                if(i>j) continue;
                int mini=1e9;
                for(int ind=i;ind<=j;ind++){
                    int cut=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                    mini=min(mini,cut);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }
};