class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> presum(n,0);
        presum[0]=nums[0];
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+nums[i];
        }
        unordered_map<int,int> s;
        int count=0;
        for(int i=0;i<n;i++){
            
            if(presum[i]==k){
                count++;
            }
            if(s.find(presum[i]-k)!=s.end()){
                count+=s[presum[i]-k];
            }
            s[presum[i]]++;
        }
        return count;
    }
};