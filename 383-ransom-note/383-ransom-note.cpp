class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(int i=0;i<ransomNote.size();i++){
            mp[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.size();i++){
            if(mp.find(magazine[i])!=mp.end()){
                mp[magazine[i]]--;
                if(mp[magazine[i]]==0){
                    mp.erase(magazine[i]);
                }
            }
        }
        return mp.empty();
    }
};