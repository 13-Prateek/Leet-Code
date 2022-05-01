class Solution {
public:
    void helper(string s,string &news){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
        }
        int bkcount=0;
        while(!st.empty()){
            if(st.top()=='#'){
                bkcount++;
                st.pop();
            }
            else{
                if(bkcount==0){
                    news+=st.top();
                    st.pop();
                }
                else{
                    bkcount--;
                    st.pop();
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