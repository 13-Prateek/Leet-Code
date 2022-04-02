class Solution {
public:
    bool isSafe(vector<vector<int>> board,int row,int col){
        for(int i=0;i<col;i++){
            if(board[row][i]==1){
                return false;
            }
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]==1){
                return false;
            }
        }
        for(int i=row,j=col;i<board.size() && j>=0;i++,j--){
            if(board[i][j]==1){
                return false;
            }
        }
        return true;
    }
    bool utility(vector<vector<int>> &board, vector<vector<string>> &ans, int n, int col){
        if(col==n){
            vector<string> temp;
            for(int i=0;i<n;i++){
                string s;
                for(int j=0;j<col;j++){
                    if(board[i][j]==1){
                        s=s+'Q';
                    }
                    else{
                        s=s+'.';
                    }
                }
                temp.push_back(s);
            }
            ans.push_back(temp);
            return true;
        }
            for(int row=0;row<n;row++){
                if(isSafe(board,row,col)){
                    board[row][col]=1;
                    utility(board,ans,n,col+1);
                    board[row][col]=0;
                }
            }
        return false;
        }                              
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<string>> ans;
        utility(board,ans,n,0);
        return ans;
    }
};