class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int ans=0,n=arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        priority_queue<int> pq;
        for(auto it: mp){
            pq.push(it.second);
        }
        int m=n;
        while(n>m/2 &&  !pq.empty()){
            n=n-pq.top();
            ans++;
            pq.pop();
        }
        return ans;
    }
};