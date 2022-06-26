class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int x=0;
        int curr_sum=0;
        int totsum=0;
        for(int i=0;i<n;i++){
            if(x<n-k){
                curr_sum+=cardPoints[i];
                x++;
            }
            totsum+=cardPoints[i];
        }
        if(k==n){
            return totsum;
        }
        int minsum=curr_sum;
        for(int i=x;i<n;i++){
            curr_sum+=cardPoints[i]-cardPoints[i-x];
            minsum=min(minsum,curr_sum);
        }
        return totsum-minsum;
    }
};