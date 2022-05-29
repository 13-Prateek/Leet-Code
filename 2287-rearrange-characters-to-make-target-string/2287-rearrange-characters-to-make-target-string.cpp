class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char,int> mp ; 
        for(auto a : target) {
             mp[a] ++;
        }
        map<char , int> mpp ; 
        for(auto a : s) {
            mpp[a] ++ ; 
        }
        int mn = INT_MAX  ; 
        for(auto a : mp ) {
             mn = min(mn , mpp[a.first]/a.second); 
        }
        return mn ; 
    }
};