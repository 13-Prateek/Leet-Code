class Solution {
public:
    int strStr(string txt, string pat) {
        if(pat.empty()){
            return 0;
        }
        int n=txt.length();
        int m=pat.length();
        for(int i=0;i<=n-m;i++){
            int j;
            for(j=0;j<m;j++){
                if(txt[i+j]!=pat[j]){
                    break;
                }
            }
            if(j==m){
                return i;
            }
        }
        return -1;
    }
};