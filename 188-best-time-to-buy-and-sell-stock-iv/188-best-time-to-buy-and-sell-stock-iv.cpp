class Solution {
public:
    // int recur(int ind,int buy, int k, int n, vector<int> &prices,vector<vector<vector<int>>> &dp){
    //     if(ind==n){
    //         return 0;
    //     }
    //     if(k==0){
    //         return 0;
    //     }
    //     if(dp[ind][buy][k]!=-1){
    //         return dp[ind][buy][k];
    //     }
    //     int profit=0;
    //     if(buy==1){
    //         profit=max(-prices[ind]+recur(ind+1,0,k,n,prices,dp),
    //                    0+recur(ind+1,1,k,n,prices,dp));
    //     }
    //     else{
    //         profit=max(prices[ind]+recur(ind+1,1,k-1,n,prices,dp),
    //                    0+recur(ind+1,0,k,n,prices,dp));
    //     }
    //     return dp[ind][buy][k]=profit;
    // }
    int maxProfit(int K, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> ahead(2,vector<int> (K+1,0));    
        vector<vector<int>> cur(2,vector<int> (K+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int k=1;k<=K;k++){
                    int profit=0;
                    if(buy==1){
                        profit=max(-prices[ind]+ahead[0][k],0+ahead[1][k]);
                    }
                    else{
                        profit=max(prices[ind]+ahead[1][k-1],0+ahead[0][k]);
                    }
                    cur[buy][k]=profit;
                }
                ahead=cur;
            }
        }
        return ahead[1][K];
    }
};