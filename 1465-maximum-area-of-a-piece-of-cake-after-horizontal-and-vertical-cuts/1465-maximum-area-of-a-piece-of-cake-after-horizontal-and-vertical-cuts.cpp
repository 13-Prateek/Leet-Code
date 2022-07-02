class Solution {
public:
    int mod=1e9+7;
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        sort(hCuts.begin(),hCuts.end());
        sort(vCuts.begin(),vCuts.end());
        int maxhd=max(hCuts[0],h-hCuts[hCuts.size()-1])%mod,maxvd=max(vCuts[0],w-vCuts[vCuts.size()-1])%mod;
        int currhd=0;
        int currvd=0;
        for(int i=1;i<hCuts.size();i++){
            currhd=hCuts[i]-hCuts[i-1];
            maxhd=max(maxhd,currhd)%mod;
        }
        for(int i=1;i<vCuts.size();i++){
            currvd=vCuts[i]-vCuts[i-1];
            maxvd=max(maxvd,currvd)%mod;
        }
        long long ans=(long(maxhd)*long(maxvd))%mod;
        return ans;
    }
};