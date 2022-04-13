class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> s1,s2;
        for(int i=0;i<nums2.size();i++){
            s1.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            int maxi=INT_MIN;
            while(s1.top()!=nums1[i]){
                int x=s1.top();
                s1.pop();
                if(x>nums1[i]){
                    maxi=x;
                }
                s2.push(x);
            }
            if(maxi==INT_MIN){
                ans.push_back(-1);
            }
            else{
                ans.push_back(maxi);
            }
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        return ans;
    }
};