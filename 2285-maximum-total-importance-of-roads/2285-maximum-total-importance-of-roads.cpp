class Solution {
public:
    static bool mycomp(pair<int,int>a, pair<int,int>b){
        return a.first>b.first;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        for(auto it: roads){
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        vector<pair<int,int>> ind;
        for(int i=0;i<n;i++){
            ind.push_back({indegree[i],i});
        }
        sort(ind.begin(),ind.end(),mycomp);
        int count=n;
        for(int i=0;i<n;i++){
            indegree[ind[i].second]=count;
            count--;
        }
        long long ans=0;
        for(auto it: roads){
            ans+=indegree[it[0]]+indegree[it[1]];
        }
        return ans;
    }
};