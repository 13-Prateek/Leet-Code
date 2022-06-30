class Solution {
public:
    // int recur(int ind1,int ind2, string s1,string s2){
    //     if(ind1<0 || ind2<0){
    //         return 0;
    //     }
    //     if(s1[ind1]==s2[ind2]){
    //         return 1+recur(ind1-1,ind2-1,s1,s2);
    //     }
    //     return max(recur(ind1-1,ind2,s1,s2),recur(ind1,ind2-1,s1,s2));
    // }
    int minInsertions(string s) {
        string rev=s;
        reverse(s.begin(),s.end());
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s[ind1-1]==rev[ind2-1]){
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        return n-dp[n][n];
    }
};