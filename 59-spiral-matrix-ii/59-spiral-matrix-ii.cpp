class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int row=n;
        int col=n;
        int count=1;
        vector<vector<int>> spiral(row,vector<int>(col));
        int top=0,right=row-1,bottom=col-1,left=0;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                spiral[top][i]=count++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                spiral[i][right]=count++;
            }
            right--;
            for(int i=right;i>=left;i--){
                spiral[bottom][i]=count++;
            }
            bottom--;
            for(int i=bottom;i>=top;i--){
                spiral[i][left]=count++;
            }
            left++;
        }
        return spiral;
    }
};