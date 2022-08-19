class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        int n = nums.size();
       
        unordered_map<int, int> count;
        
        // end will store the no. of subsequence ending with nums[i]
        
        unordered_map<int, int> end;
        
        // store the frequency of each element in count map
        
        for(int i = 0; i < n; i++)
        {
            count[nums[i]]++;
        }
        
        // iterate over the nums array
        
        for(int i = 0; i < n; i++)
        {
            // if nums[i] is already included
            
            if(count[nums[i]] == 0)
                continue;
            
            // decrement the frequency of curr element
            
            count[nums[i]]--;
            
            // 1st check can we include in existing subsequence
            
            if(end[nums[i] - 1] > 0)
            {
                end[nums[i] - 1]--;
                
                end[nums[i]]++;
            }
            
            // 2nd check can we form a new subsequence starting with nums[i] and ending with nums[i] + 2
            
            else if(count[nums[i] + 1] && count[nums[i] + 2])
            {
                count[nums[i] + 1]--;
                
                count[nums[i] + 2]--;
                
                end[nums[i] + 2]++;
            }
            
            // otherwise return false
            
            else
                return false;
        }
        
        return true;
    }
};