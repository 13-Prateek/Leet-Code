class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0;
        int i=0,j=tokens.size()-1;
        int maxi=0;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                power-=tokens[i];
                i++;
            }
            else{
                if(score==0){
                    break;
                }
                score--;
                power+=tokens[j];
                j--;
            }
            maxi=max(score,maxi);
        }
        return maxi;
    }
};