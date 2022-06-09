class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=1;
        if(nums.size()==1){
            return {nums[0]};
        }
        vector<int> res;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
            }
            else{
                if(count>nums.size()/3){
                    res.push_back(nums[i]);
                }
                count=1;
            }
        }
        if(count>nums.size()/3){
                    res.push_back(nums[nums.size()-1]);
        }
        return res;
    }
};