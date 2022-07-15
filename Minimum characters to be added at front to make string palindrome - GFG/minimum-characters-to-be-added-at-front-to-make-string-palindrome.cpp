// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int minChar(string str){
        //Write your code here
        int n=str.length();
    int ans=0;
    int i=0,j=n-1;
    while(i<j){
        if(str[i]==str[j]){
            i++,j--;
        }
        else{
            i=0;
            ans=n-j;
            if(str[i]==str[j]){
                ans--;
                i++;
            }
            j--;
        }
    }
    return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends