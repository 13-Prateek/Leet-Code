class Solution {
public:
    int climbStairs(int n) {
        // if(n==0 || n==1){
        //     return 1;
        // }
        // int onej=climbStairs(n-1);
        // int twoj=climbStairs(n-2);
        // return onej+twoj;
        //vector<int> dp(n+1,-1);
        // dp[0]=1;
        // dp[1]=1;
        int prev=1,prev2=1;
        for(int i=2;i<=n;i++){
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};