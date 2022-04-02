class Solution {
public:
    void utility(int freq[], vector<int> &nums, vector<vector<int>> &ans,vector<int> &temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                temp.push_back(nums[i]);
            freq[i]=1;
            utility(freq,nums,ans,temp);
            freq[i]=0;
            temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int freq[nums.size()];
        for (int i = 0; i < nums.size(); i++) freq[i] = 0;
        utility(freq,nums,ans,temp);
        return ans;
    }
};