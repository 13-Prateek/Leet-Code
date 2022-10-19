class Solution {
public:
    class Compare{
        public:
            bool operator() (pair<int,string> a, pair<int,string> b){
                if(a.first!=b.first){
                    return a.first<b.first;
                }
                else{
                    return a.second>b.second;
                }
            }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto it:words){
            mp[it]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare> pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};