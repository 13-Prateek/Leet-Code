class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> temp(26,0);
        for(int i=0;i<sentence.length();i++){
            temp[sentence[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(temp[i]==0){
                return false;
            }
        }
        return true;
    }
};