class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1){
            return nums[0];
        }
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n-1;i++){
            int pick=nums[i]+prev2;
            int notpick=prev;
            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        int ans1=prev;
        prev=nums[1];
        prev2=0;
        for(int i=2;i<n;i++){
            int pick=nums[i]+prev2;
            int notpick=prev;
            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        int ans2=prev;
        return max(ans1,ans2);
    }
};