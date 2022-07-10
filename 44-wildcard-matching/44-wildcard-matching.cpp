class Solution {
public:
    bool isAllStars(string & S1, int i) {

        // S1 is taken in 1-based indexing
          for (int j = 1; j <= i; j++) {
            if (S1[j - 1] != '*')
              return false;
          }
          return true;
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=false;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=isAllStars(p,j);
        }
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               if(s[i-1]==p[j-1] || p[j-1]=='?'){
                     dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                     dp[i][j]=(dp[i][j-1] || dp[i-1][j]);
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[n][m];
    }
};