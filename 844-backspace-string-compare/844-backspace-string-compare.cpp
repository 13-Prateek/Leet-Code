class Solution {
public:
    void helper(string s,string &news){
        int i=s.size()-1;
        int bkcount=0;
        while(i>=0){
            if(s[i]=='#'){
                bkcount++;
                i--;
            }
            else{
                if(bkcount==0){
                    news+=s[i];
                    i--;
                }
                else{
                    bkcount--;
                    i--;
                }
            }
        }
    }
    bool backspaceCompare(string s, string t) {
        string news="",newt="";
        helper(s,news);
        helper(t,newt);
        if(news.size()!=newt.size()) return false;
        for(int i=0;i<news.size();i++){
            if(news[i]!=newt[i]){
                return false;
            }
        }
        return true;
    }
};