class Solution {
public:
    // int recur(int ind, vector<int>& nums, vector<int>& dp){
    //     if(ind==0){
    //         return nums[ind];
    //     }
    //     if(ind<0){
    //         return 0;
    //     }
    //     if(dp[ind]!=-1){
    //         return dp[ind];
    //     }
    //     int pick=nums[ind]+recur(ind-2,nums,dp);
    //     int notPick=recur(ind-1,nums,dp);
    //     return dp[ind]=max(pick,notPick);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1){
                pick+=dp[i-2];
            }
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
};