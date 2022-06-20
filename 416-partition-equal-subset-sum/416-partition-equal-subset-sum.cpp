class Solution {
public:
    // bool recur(int ind, int target, vector<int>& nums,vector<vector<int>>& dp){
    //     if(target==0){
    //         return true;
    //     }
    //     if(ind==0){
    //         return nums[ind]==target;
    //     }
    //     if(dp[ind][target]!=-1){
    //         return dp[ind][target];
    //     }
        // bool notpick=recur(ind-1,target,nums,dp);
        // bool pick=false;
        // if(nums[ind]<=target){
        //     pick=recur(ind-1,target-nums[ind],nums,dp);
        // }
        // return dp[ind][target]=pick||notpick;
    // }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int k=sum/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=k){
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                bool notpick=dp[i-1][target];
                bool pick=false;
                if(nums[i]<=target){
                    pick=dp[i-1][target-nums[i]];
                }
                dp[i][target]=pick||notpick;
            }
        }
        return dp[n-1][k];
    }
};