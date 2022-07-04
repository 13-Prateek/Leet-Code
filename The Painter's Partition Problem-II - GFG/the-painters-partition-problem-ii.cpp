// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  #define ll long long
    bool isPossible(int board, int arr[], int n, int k){
        int cnt=1;
        ll allo=0;
        for(ll i=0;i<n;i++){
            if(allo+arr[i]>board){
                cnt++;
                allo=arr[i];
                if(allo>board){
                    return false;
                }
            }
            else{
                allo+=arr[i];
            }
        }
        if(cnt<=k){
            return true;
        }
        return false;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        int low=0;
        ll high=0;
        for(ll i=0;i<n;i++){
            high+=arr[i];
            low=min(low,arr[i]);
        }
        ll res=0;
        while(low<=high){
            ll mid=(low+high)>>1;
            if(isPossible(mid,arr,n,k)){
                high=mid-1;
                res=mid;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends