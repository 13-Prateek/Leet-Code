class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s[0]=='}' || s[0]==')' || s[0]==']'){
            return false;
        }
        for(int i=0;i<s.size();i++){
             if(st.empty() && (s[i]=='}' || s[i]==')' || s[i]==']')){
            return false;
        }
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(!st.empty() && st.top()!='('){
                    return false;
                }
                else{
                    st.pop();
                }
            }
             else if(s[i]==']'){
                if(!st.empty() && st.top()!='['){
                    return false;
                }
                else{
                    st.pop();
                }
            }
             else if(s[i]=='}'){
                if(!st.empty() && st.top()!='{'){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};