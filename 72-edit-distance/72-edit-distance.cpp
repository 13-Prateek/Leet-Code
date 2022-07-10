class Solution {
public:
    int recur(int i, int j, string &s1, string &s2,vector<vector<int>>& dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=0+recur(i-1,j-1,s1,s2,dp);
        }
        else{
            return dp[i][j]=1+min(recur(i,j-1,s1,s2,dp),min(recur(i-1,j,s1,s2,dp),recur(i-1,j-1,s1,s2,dp)));
        }
    }
    int minDistance(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n,vector(m,-1));
        return recur(n-1,m-1,s1,s2,dp);
    }
};