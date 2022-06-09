class Solution {
public:
    void helper(int ind, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        if(ind==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        helper(ind+1,nums,temp,ans);
        temp.pop_back();
        helper(ind+1,nums,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0,nums,temp,ans);
        return ans;
    }
};