class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int num:nums){
            s.insert(num);
        }
        int longestStreak=0;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)==s.end()){
                int curr_num=nums[i];
                int curr_streak=1;
                while(s.find(curr_num+1)!=s.end()){
                    curr_num++;
                    curr_streak++;
                }
                longestStreak=max(longestStreak,curr_streak);
            }
        }
        return longestStreak;
    }
};