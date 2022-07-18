class Solution {
public:
    //  int recur(int ind, int buy, int n,int fee, vector<int> &prices,vector<vector<int>> &dp){
    //     if(ind==n){
    //         return 0;
    //     }
    //     if(dp[ind][buy]!=-1){
    //         return dp[ind][buy];
    //     }
    //     int profit=0;
    //     if(buy==1){
    //         profit=max(-prices[ind]+recur(ind+1,0,n,fee,prices,dp),0+recur(ind+1,1,n,fee,prices,dp));
    //     }
    //     else{
    //         profit=max(prices[ind]-fee+recur(ind+1,1,n,fee,prices,dp),0+recur(ind+1,0,n,fee,prices,dp));
    //     }
    //     return dp[ind][buy]=profit;
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> ahead(2,0), cur(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit;
                if(buy==1){
                    profit=max(-prices[ind]+ahead[0],0+ahead[1]);
                }
                else{
                    profit=max(prices[ind]-fee+ahead[1],0+ahead[0]);
                }
                cur[buy]=profit;
            }
            ahead=cur;
        }
        return ahead[1];
    }
};