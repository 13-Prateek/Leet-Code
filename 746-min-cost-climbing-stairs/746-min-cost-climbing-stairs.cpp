class Solution {
public:
    int recur(int ind, vector<int>& cost, int n,vector<int>& dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int onestep=recur(ind+1,cost,n,dp)+cost[ind];
        int twostep=INT_MAX;
        if(ind<n-1){
            twostep=recur(ind+2,cost,n,dp)+cost[ind];
        }
        return dp[ind]=min(onestep,twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        int ind0=recur(0,cost,n,dp);
        fill(dp.begin(),dp.end(),-1);
        int ind1=recur(1,cost,n,dp);
        return min(ind0,ind1);
    }
};