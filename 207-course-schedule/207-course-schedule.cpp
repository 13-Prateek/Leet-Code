class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& prereq) {
        vector<int> adj[v];
        for(int i=0;i<prereq.size();i++){
            adj[prereq[i][1]].push_back(prereq[i][0]);
        }
        vector<int> indegree(v,0);
	    for(int i=0;i<v;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<v;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
        if(ans.size()==v){
            return true;
        }
        return false;
    }
};