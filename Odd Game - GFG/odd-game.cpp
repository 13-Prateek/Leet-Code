// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long oddGame(long long N) {
        // code here
        long long ans=1;
    if(N==1)
       return 1;
    while(N>1)
    {
        ans=ans<<1;
        N=N>>1;
    }
     return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.oddGame(N) << endl;
    }
    return 0;
}  // } Driver Code Ends