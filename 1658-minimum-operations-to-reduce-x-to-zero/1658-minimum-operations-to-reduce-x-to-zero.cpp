class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0,max_len=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int target=sum-x;
        if(target==0){
            return nums.size();
        }
        //sliding window
        int st_ind=0,end_ind=0,curr_sum=0;
        for(end_ind=0;end_ind<nums.size();end_ind++){
            curr_sum+=nums[end_ind];
            while(curr_sum>target && st_ind<=end_ind){
                curr_sum-=nums[st_ind++];
            }
            if(curr_sum==target){
                max_len=max(max_len,end_ind-st_ind+1);
            }
        }
        return max_len?nums.size()-max_len:-1;
    }
};