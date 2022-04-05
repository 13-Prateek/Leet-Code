class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=INT_MIN;
        int i=0,j=height.size()-1;
        while(i<j){
            int x=j-i;
            int contain=min(height[i],height[j])*x;
            ans=max(ans,contain);
            if(height[i]>=height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};