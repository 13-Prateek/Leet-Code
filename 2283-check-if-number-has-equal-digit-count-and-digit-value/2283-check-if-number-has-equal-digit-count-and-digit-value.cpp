class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int,int> mpp;
        int n= num.length();
        for(auto it:num){
            int x = it - '0';
            mpp[x]++;
        }
        for(int i=0;i<n;i++){
            int x = num[i] - '0';
            if(x == 0 && mpp.find(i) != mpp.end())
                return false;
            else if(mpp[i] != x)
                return false;
        }
        return true;
    }
};