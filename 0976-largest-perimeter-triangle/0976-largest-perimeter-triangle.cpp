class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=n-1,j=n-2,k=n-3;
        while(i>=0 && j>=0 and k>=0){
            if(nums[k]+nums[j]>nums[i]){
                return nums[k]+nums[j]+nums[i];
            }
            i--,j--,k--;
        }
        return 0;
    }
};