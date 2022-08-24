class Solution {
public:
    bool isPowerOfThree(int n) {
        if(!n){
            return false;
        }
        while(n!=0 && n!=1){
            if(n%3!=0){
                return false;
            }
            n=n/3;
        }
        if(n==1){
            return true;
        }
        return false;
    }
};