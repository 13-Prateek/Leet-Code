class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;
        sort(potions.begin(),potions.end());
        int n=potions.size();
        for(int i=0;i<spells.size();i++){
            int count=0;
            int low=0,high=potions.size()-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                long long st=long(spells[i])*potions[mid];
                if(st>=success){
                    high=mid-1;
                    count=n-mid;
                }
                else{
                    low=mid+1;
                }
            }
            pairs.push_back(count);
        }
        return pairs;
    }
};