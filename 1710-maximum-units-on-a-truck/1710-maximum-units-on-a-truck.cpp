class Solution {
public:
    bool static myComp(vector<int> a, vector<int> b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),myComp);
        int ans=0;
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0]>truckSize){
                ans+=(truckSize*boxTypes[i][1]);
                break;
            }
            else{
                ans+=(boxTypes[i][0]*boxTypes[i][1]);
                truckSize-=boxTypes[i][0];
            }
        }
        return ans;
    }
};