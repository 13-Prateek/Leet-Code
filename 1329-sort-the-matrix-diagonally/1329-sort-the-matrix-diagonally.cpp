class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& matrix) {
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mp;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].push(matrix[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp.find(i-j)!=mp.end()){
                    matrix[i][j]=mp[i-j].top();
                    mp[i-j].pop();
                }
            }
        }
        return matrix;
    }
};