class Solution {
public:
    int recur(int i,int j, string s1, string s2,vector<vector<int>> &dp){
        if(i<0|| j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=1+recur(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j]=max(recur(i-1,j,s1,s2,dp),recur(i,j-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n+1,vector(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    }
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};