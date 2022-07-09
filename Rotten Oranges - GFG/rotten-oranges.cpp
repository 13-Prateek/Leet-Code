// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        int n=grid.size(), m=grid[0].size(), totorng=0,cnt=0,mins=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0) totorng++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        while(!q.empty()){
            int k=q.size();
            cnt+=k;
            while(k--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]!=1){
                        continue;
                    }
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty()){
                mins++;
            }
        }
        if(totorng==cnt){
            return mins;
        }
        return -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends