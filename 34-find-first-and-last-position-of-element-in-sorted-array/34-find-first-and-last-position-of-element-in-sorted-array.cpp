class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int start=-1,end=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                if(start==-1){
                    start=i;
                }
                
                    if(i==n-1 || nums[i]!=nums[i+1]){
                        end=i;
                    
                }
            }
        }
        return {start,end};
    }
};