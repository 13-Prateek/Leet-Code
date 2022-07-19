class Solution {
public:
    int recur(int ind, int prev, int n, vector<int> &nums,vector<vector<int>> &dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int len=0+recur(ind+1,prev,n,nums,dp);
         if(prev==-1 || nums[ind]>nums[prev]){
            len=max(len,1+recur(ind+1,ind,n,nums,dp));
        }
        return dp[ind][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int len=0+dp[ind+1][prev+1];
                if(prev==-1 || nums[ind]>nums[prev]){
                    len=max(len,1+dp[ind+1][ind+1]);
                }
                dp[ind][prev+1]=len;
            }
        }
        return dp[0][0];
    }
};