class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans=0;
        for(auto it:mp){
            int num=it.first, count=it.second;
            if(num==k-num){
                ans+=count/2;
                mp[num]=0;
            }
            else if(mp.count(k-num)){
                int mini=min(count,mp[k-num]);
                ans+=mini;
                mp[num]-=mini;
                mp[k-num]-=mini;
            }
        }
        return ans;
    }
};