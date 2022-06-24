class Solution {
public:
    // int recur(int ind, int tar, vector<int>& coins,vector<vector<int>> &dp){
    //     if(ind==0){
    //         return (tar%coins[ind]==0);
    //     }
    //     if(dp[ind][tar]!=-1){
    //         return dp[ind][tar];
    //     }
    //     int notpick=recur(ind-1,tar,coins,dp);
    //     int pick=0;
    //     if(coins[ind]<=tar){
    //         pick=recur(ind,tar-coins[ind],coins,dp);
    //     }
    //     return dp[ind][tar]=pick+notpick;
    // }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-0));
        for(int tar=0;tar<=amount;tar++){
            dp[0][tar]=(tar%coins[0]==0);
        }
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=amount;tar++){
                int notpick=dp[ind-1][tar];
                int pick=0;
                if(coins[ind]<=tar){
                    pick=dp[ind][tar-coins[ind]];
                }
                dp[ind][tar]=pick+notpick;
            }
        }
        return dp[n-1][amount];
    }
};