// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long long
class Solution{
    const long long mod = 1000000007;
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        
       vector<vector<ll>> arr(n , vector<ll>(n , 0));
        arr[0][0] = 1;
        if(n==1) return arr[0];
        arr[1][0] = arr[1][1] = 1;
        if(n==2) return arr[1];
        for(int i=2 ; i < n ; i++){
            arr[i][0] = 1;
            for(int j = 1 ; j<=i ; j++){
                arr[i][j] = ((arr[i-1][j] % mod) +
                (arr[i-1][j-1] % mod)) % mod;
            }
        }
        return arr[n-1];
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends