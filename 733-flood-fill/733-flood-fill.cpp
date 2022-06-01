class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int row=image.size();
        int col=image[0].size();
        int oc=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> vis(row,vector<int> (col,0));
        vis[sr][sc]=1;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            image[p.first][p.second]=newColor;
            for(int i=0;i<4;i++){
                int x=p.first+dx[i];
                int y=p.second+dy[i];
                if(x>=0 && y>=0 && x<row && y<col && vis[x][y]!=1 && image[x][y]==oc){
                    q.push({x,y});
                    vis[x][y]=1;
                }
            }
        }
        return image;
    }
};