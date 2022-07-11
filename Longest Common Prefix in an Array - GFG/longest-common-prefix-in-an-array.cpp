// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string strs[], int n)
    {
        // your code here
        sort(strs,strs+n);
        string s1=strs[0];
        string s2=strs[n-1];
        string ans="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                break;
            }
            else{
                ans+=s1[i];
            }
        }
        if(ans.empty()){
            return "-1";
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends