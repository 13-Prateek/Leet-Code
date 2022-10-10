class Solution {
public:
    string breakPalindrome(string palin) {
        if(palin.length()==1){
            return "";
        }
        int i=0,j=palin.length()-1;
        while(i<j){
            if(palin[i]!='a'){
                palin[i]='a';
                return palin;
            }
            i++;
            j--;
        }
        palin[palin.length()-1]='b';
        return palin;
    }
};