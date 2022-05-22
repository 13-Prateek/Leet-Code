// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}

// } Driver Code Ends


int CountPS(char S[], int N)
{
    //code here
    
    int count = 0, x, y;
    vector<vector<int>> dp(N, vector<int>(N, 0));
    
    for(int i=0; i<N; i++){
        dp[i][i] = 1;
    }
    
    for(int i=0; i<N-1; i++){
        if(S[i] == S[i+1]){
            dp[i][i+1] = 1;
            count += 1;
        }
    }
    
    for(int i=2; i<N; i++){
        x = 0;
        y = i;
        
        while(y < N){
            if(S[x] == S[y] and dp[x+1][y-1]){
                dp[x][y] = 1;
                count += 1;
            }
            
            x++;
            y++;
        }
    }
    
    return count;
    
}