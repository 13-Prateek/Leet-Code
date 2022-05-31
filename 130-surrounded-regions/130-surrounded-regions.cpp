class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int x,int y, int row, int col,vector<vector<char>>& board){
        if(x<0 || y<0 || x>=row || y>=col || board[x][y]!='O'){
            return;
        }
        board[x][y]='#';
        for(int i=0;i<4;i++){
            dfs(x+dx[i],y+dy[i],row,col,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        if(row==0)return;
        int col=board[0].size();
        
        for(int i=0;i<col;i++){
            if(board[0][i]=='O'){
                dfs(0,i,row,col,board);
            }
            if(board[row-1][i]=='O'){
                dfs(row-1,i,row,col,board);
            }
        }
        for(int i=0;i<row;i++){
            if(board[i][0]=='O'){
                dfs(i,0,row,col,board);
            }
            if(board[i][col-1]=='O'){
                dfs(i,col-1,row,col,board);
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        
    }
};