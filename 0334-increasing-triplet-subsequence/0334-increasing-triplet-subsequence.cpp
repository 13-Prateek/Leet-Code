class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return false;
        }
        int l1=INT_MAX,l2=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]>l2){
                return true;
            }
            else if(nums[i]<l1){
                l1=nums[i];
            }
            else if(nums[i]>l1 && nums[i]<l2){
                l2=nums[i];
            }
        }
        return false;
    }
};