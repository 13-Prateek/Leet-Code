class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n);
        vector<int> right(n);
        
        int res=0;
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(height[i],left[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        for(int i=1;i<n-1;i++){
            res+=min(left[i],right[i])-height[i];
        }
        return res;
    }
};