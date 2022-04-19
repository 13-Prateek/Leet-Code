class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s1=strs[0];
        string s2=strs[strs.size()-1];
        string ans="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                break;
            }
            else{
                ans+=s1[i];
            }
        }
        return ans;
    }
};