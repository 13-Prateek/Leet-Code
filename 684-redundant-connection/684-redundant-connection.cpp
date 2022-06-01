class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find_parent(int a){
        if(a==parent[a]){
            return a;
        }
        else{
            return parent[a]=find_parent(parent[a]);
        }
    }
    bool unionn(int a, int b){
        int par_a=find_parent(a);
        int par_b=find_parent(b);
        if(par_a==par_b)return false;
        if(rank[par_a]<rank[par_b]){
            parent[par_a]=par_b;
        }
        else if(rank[par_a]>rank[par_b]){
            parent[par_b]=par_a;
        }
        else{
            parent[par_b]=par_a;
            rank[par_a]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent=vector<int>(1001);
        rank=vector<int>(1001);
        for(int i=0;i<1001;i++){
            parent[i]=i;
            rank[i]=0;
        }
        for(auto it: edges){
            if(!unionn(it[0],it[1]))return it;
        }
        return {};
    }
};