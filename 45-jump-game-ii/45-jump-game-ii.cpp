class Solution {
public:
    int recur(int ind, vector<int>& nums,vector<int>& dp,int n){
        if(ind>=n-1){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int minjump=1e9;
        for(int i=1;i<=nums[ind];i++){
            int x=1+recur(ind+i,nums,dp,n);
            minjump=min(minjump,x);
        }
        return dp[ind]=minjump;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return recur(0,nums,dp,n);
    }
};