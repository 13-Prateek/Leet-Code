class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int s1=pq.top();
            pq.pop();
            int s2=pq.top();
            pq.pop();
            int x=abs(s1-s2);
            if(x!=0){
                pq.push(x);
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};