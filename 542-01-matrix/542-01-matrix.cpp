class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>> dis(row,vector<int> (col,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=p.first+dx[i];
                int y=p.second+dy[i];
                if(x<0 || y<0 || x>=row || y>=col || dis[x][y]!=-1){
                    continue;
                }
                q.push({x,y});
                dis[x][y]=dis[p.first][p.second]+1;
            }
        }
        return dis;
    }
};