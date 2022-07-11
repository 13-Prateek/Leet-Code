class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n=price.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
               int profit=0;
                if(buy){
                    profit=max(-price[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                }
                else{
                    profit=max(price[ind]+dp[ind+1][1],0+dp[ind+1][0]);
                }
                dp[ind][buy]=profit; 
            }
        }
        return dp[0][1];
    }
};