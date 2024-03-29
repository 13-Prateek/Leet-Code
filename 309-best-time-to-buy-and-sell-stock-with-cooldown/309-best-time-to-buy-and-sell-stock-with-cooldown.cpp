class Solution {
public:
    int recur(int ind, int buy, int n, vector<int> &prices,vector<vector<int>> &dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int profit=0;
        if(buy==1){
            profit=max(-prices[ind]+recur(ind+1,0,n,prices,dp),0+recur(ind+1,1,n,prices,dp));
        }
        else{
            profit=max(prices[ind]+recur(ind+2,1,n,prices,dp),0+recur(ind+1,0,n,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit;
                if(buy==1){
                    profit=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                }
                else{
                    profit=max(prices[ind]+dp[ind+2][1],0+dp[ind+1][0]);
                }
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};