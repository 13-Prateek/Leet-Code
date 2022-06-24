class Solution {
public:
    int recur(int ind, vector<int>& nums, int target,vector<vector<int>> &dp){
        if(ind==0){
            if(nums[ind]==0 && target==0){
                return 2;
            }
            if(nums[ind]==target || target==0){
                return 1;
            }
            return 0;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int notpick=recur(ind-1,nums,target,dp);
        int pick=0;
        if(nums[ind]<=target){
            pick=recur(ind-1,nums,target-nums[ind],dp);
        }
        return dp[ind][target]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if((sum-target)<0 || (sum-target)%2!=0){
            return 0;
        }
        int k=(sum-target)/2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return recur(n-1,nums,k,dp);
    }
};