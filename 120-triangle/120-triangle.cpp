class Solution {
public:
    int recur(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=triangle[i][j]+recur(i+1,j,triangle,dp);
        int diag=triangle[i][j]+recur(i+1,j+1,triangle,dp);
        return dp[i][j]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[i].resize(i+1);
        }
        return recur(0,0,triangle,dp);
    }
};