class Solution {
public:
    // static bool myComp(pair<string,int>a,pair<string,int>b){
    //     if(a.first!=b.first){
    //         return a.first<b.first;
    //     }
    //     else{
    //         return a.second<b.second;
    //     }
    // }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.size()==0){
            return res;
        }
        // if(strs.size()==1){
        //     res.push_back(strs);
        //     return res;
        // }
        vector<pair<string,int>> temp;
        for(int i=0;i<strs.size();i++){
            string dummy=strs[i];
            sort(dummy.begin(),dummy.end());
            temp.push_back({dummy,i});
        }
        sort(temp.begin(),temp.end());
        string dum=temp[0].first;
        int n=temp.size();
        int i=0;
        while(i<n){
            vector<string> ghd;
            string s=temp[i].first;
            while(i<n && temp[i].first==s){
                ghd.push_back(strs[temp[i].second]);
                i++;
            }
            res.push_back(ghd);
        }
        return res;
    }
};