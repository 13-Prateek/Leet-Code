class Solution {
public:
    int recur(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j<0 || j>matrix.size()-1){
            return 100000;
        }
        if(i==0){
            return matrix[i][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int s=matrix[i][j]+recur(i-1,j,matrix,dp);
        int ld=matrix[i][j]+recur(i-1,j-1,matrix,dp);
        int rd=matrix[i][j]+recur(i-1,j+1,matrix,dp);
        return dp[i][j]=min(s,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            int small=recur(n-1,j,matrix,dp);
            mini=min(mini,small);
        }
        return mini;
    }
};