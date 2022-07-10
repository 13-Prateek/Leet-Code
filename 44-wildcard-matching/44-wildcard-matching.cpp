class Solution {
public:
    bool recur(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i<0 && j<0){ //both strings exhausted
            return true;
        }
        if(i>=0 && j<0){// 1st string exhaused but 2nd string still has characters
            return false;
        }
        if(i<0 && j>=0){// 1st string still has some characters
            for(int x=0;x<=j;x++){
                if(p[x]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //if characters match or s has ?
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=recur(i-1,j-1,s,p,dp);
        }
        /*if we encounter an * */
        if(p[j]=='*'){
            return dp[i][j]=(recur(i,j-1,s,p,dp) || recur(i-1,j,s,p,dp));
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return recur(n-1,m-1,s,p,dp);
    }
};