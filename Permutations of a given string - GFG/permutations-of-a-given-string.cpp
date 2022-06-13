// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void perm(int ind,int n, string& s, set<string>& ans){
	    if(ind==n){
	        ans.insert(s);
	        return;
	    }
	    for(int i=ind;i<n;i++){
	       // if(i>ind && s[i]==s[ind]){
	       //     continue;
	       // }
	        swap(s[i],s[ind]);
	        perm(ind+1,n,s,ans);
	        swap(s[i],s[ind]);
	    }
	}
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string> res;
		    set<string> ans;
		    int n=s.length();
		    perm(0,n,s,ans);
		    for(auto it:ans){
		        res.push_back(it);
		    }
		    return res;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends