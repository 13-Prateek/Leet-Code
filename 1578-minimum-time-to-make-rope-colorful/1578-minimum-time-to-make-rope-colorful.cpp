class Solution {
public:
    int minCost(string colors, vector<int>& nTime) {
        int ans=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<colors.size()-1;i++){
            if(colors[i]==colors[i+1]){
                pq.push(nTime[i]);
            }
            else{
                pq.push(nTime[i]);
                while(pq.size()!=1){
                    ans+=pq.top();
                    pq.pop();
                }
                pq.pop();
            }
        }
        if(pq.size()!=0){
            pq.push(nTime[colors.size()-1]);
            while(pq.size()!=1){
                ans+=pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};