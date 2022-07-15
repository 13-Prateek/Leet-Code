class Solution {
public:
    int recur(int ind, int buy,int cap, int n, vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(cap==0){
            return 0;
        }
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy][cap]!=-1){
            return dp[ind][buy][cap];
        }
        int profit=0;
        if(buy==1){
            profit=max(-prices[ind]+recur(ind+1,0,cap,n,prices,dp),
                      0+recur(ind+1,1,cap,n,prices,dp));
        }
        else{
            profit=max(prices[ind]+recur(ind+1,1,cap-1,n,prices,dp),
                      0+recur(ind+1,0,cap,n,prices,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector(2,vector(3,-1)));
        return recur(0,1,2,n,prices,dp);
    }
};