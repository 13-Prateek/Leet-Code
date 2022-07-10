class Solution {
public:
    // int recur(int i, int j, string &s1, string &s2,vector<vector<int>>& dp){
    //     if(i==0){
    //         return j;
    //     }
    //     if(j==0){
    //         return i;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(s1[i-1]==s2[j-1]){
    //         return dp[i][j]=0+recur(i-1,j-1,s1,s2,dp);
    //     }
    //     else{
    //         return dp[i][j]=1+min(recur(i,j-1,s1,s2,dp),min(recur(i-1,j,s1,s2,dp),recur(i-1,j-1,s1,s2,dp)));
    //     }
    // }
    int minDistance(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n+1,vector(m+1,0));
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=0+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};