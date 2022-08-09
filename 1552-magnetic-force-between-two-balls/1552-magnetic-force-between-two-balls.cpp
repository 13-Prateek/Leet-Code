class Solution {
public:
    bool isposi(int dist, vector<int>& posi, int m){
        int cnt=1;
        int n=posi.size();
        int lastpos=posi[0];
        for(int i=1;i<n;i++){
            if(posi[i]-lastpos>=dist){
                cnt++;
                lastpos=posi[i];
            }
            if(cnt>=m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& posi, int m) {
        sort(posi.begin(),posi.end());
        int n=posi.size();
        int low=1, high=posi[n-1]-posi[0];
        int res=0;
        while(low<=high){
            int mid=(low+high)>>1;
            if(isposi(mid,posi,m)){
                low=mid+1;
                res=mid;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
};