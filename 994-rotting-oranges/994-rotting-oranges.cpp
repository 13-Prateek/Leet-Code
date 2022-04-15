class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), tot=0,cnt=0,mins=0;
        queue<pair<int,int>> rotten;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0) tot++;
                if(grid[i][j]==2) rotten.push({i,j});
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!rotten.empty()){
            int k=rotten.size();
            cnt+=k;
            while(k--){
                int x=rotten.front().first;
                int y=rotten.front().second;
                rotten.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]!=1) continue;
                    grid[nx][ny]=2;
                    rotten.push({nx,ny});
                }
            }
            if(!rotten.empty()) mins++;
        }
        if(tot==cnt) return mins;
        return -1;
    }
};