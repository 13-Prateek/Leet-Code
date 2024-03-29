class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, int> m {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int ans=0;
        int i=0,n=s.size();
        while(i<n-1){
            if(m[s[i]]>=m[s[i+1]]){
                ans+=m[s[i]];
                i++;
            }
            else{
                ans+=m[s[i+1]]-m[s[i]];
                i=i+2;
            }
        }
        if(i==n-1){
            ans+=m[s[i]];
        }
        return ans;
    }
};