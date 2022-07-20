class Solution {
public:
    bool isposi(string s1,string s2){
        if(s1.length()!=s2.length()+1){
            return false;
        }
        int i=0,j=0;
        while(i<s1.length()){
            if(j<s2.length() && s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==s1.length() && j==s2.length()){
            return true;
        }
        return false;
        
    }
    static bool myComp(string s1, string s2){
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),myComp);
        int n=words.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(isposi(words[i],words[j]) && dp[i]<1+dp[j]){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};