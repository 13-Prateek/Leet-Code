class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(int i=0;i<ops.size();i++){
            string ch=ops[i];
            if(ch=="+"){
                int x=s.top();
                s.pop();
                int y=x+s.top();
                s.push(x);
                s.push(y);
            }
            else if(ch=="C"){
                s.pop();
            }
            else if(ch=="D"){
                s.push(2*s.top());
            }
            else{
                s.push(stoi(ch));
            }
        }
        int res=0;
        while(!s.empty()){
            res+=s.top();
            s.pop();
        }
        return res;
    }
};