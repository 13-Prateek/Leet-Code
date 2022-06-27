class Solution {
public:
    int minPartitions(string n) {
        int maxdigi=0;
        for(int i=0;i<n.size();i++){
            char c=n[i];
            maxdigi=max(maxdigi,(int(c)-int('0')));
        }
        return maxdigi;
    }
};