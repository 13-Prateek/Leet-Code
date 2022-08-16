class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> mp;
        for(int i=0;i<s.length();i++){
            char x=s[i];
            if(mp.find(x)==mp.end()){
                mp[x]={1,i};
            }
            else{
                mp[x].first++;
            }
        }
        int ans=INT_MAX;
        for(auto it:mp){
            if(it.second.first==1){
                ans=min(ans,it.second.second);
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};