// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> res;
    void helper(vector<vector<int>> &m, int row, int col, vector<vector<bool>> &visited, string psf){
        if(row<0 || row==m.size() || col<0 || col==m[0].size() || m[row][col]==0 || visited[row][col]==true){
            return;
        }
        if(row==m.size()-1 && col==m[0].size()-1){
            res.push_back(psf);
            return;
        }
        visited[row][col]=true;
        helper(m,row-1,col,visited,psf+'U');
        helper(m,row+1,col,visited,psf+'D');
        helper(m,row,col-1,visited,psf+'L');
        helper(m,row,col+1,visited,psf+'R');
        visited[row][col]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>>visited(m.size(),vector<bool>(m[0].size()));
        string psf="";
        helper(m,0,0,visited,psf);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends