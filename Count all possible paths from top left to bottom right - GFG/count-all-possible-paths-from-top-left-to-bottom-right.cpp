// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod=1e9+7;
    long long int recur(int i,int j,vector<vector<long long int>> &dp){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long int up=recur(i-1,j,dp);
        long long int left=recur(i,j-1,dp);
        return dp[i][j]=(up%mod)+(left%mod);
    }
    long long int numberOfPaths(int m, int n){
        // code here
        vector<vector<long long int>> dp(m,vector<long long int>(n,-1));
        return recur(m-1,n-1,dp)%mod;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends