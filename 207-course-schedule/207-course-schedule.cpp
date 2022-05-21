class Solution {
public:
    // bool cycledetect(int s,vector<int> adjList[], vector<int>& visited){
    //     visited[s]=1;
    //     queue<pair<int,int>> q;
    //     q.push({s,-1});
    //     while(!q.empty()){
    //         int node=q.front().first;
    //         int par=q.front().second;
    //         q.pop();
    //         for(auto it: adjList[node]){
    //             if(!visited[it]){
    //                 q.push({it,node});
    //                 visited[it]=1;
    //             }
    //             else if(it!=par){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q; vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto c : prerequisites)
        {
            adj[c[1]].push_back(c[0]);
            indegree[c[0]]++ ;
        }
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]==0){q.push(i);}
        }
        int cnt = numCourses ;
        while(!q.empty())
        {   
            int node = q.front(); q.pop(); cnt--;
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0){q.push(it);}
            }
        }
        if(cnt == 0){return true;}
        
        return false;
    }
};