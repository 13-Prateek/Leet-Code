// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int pages,int arr[], int n, int m){
        int cnt=1;
        int sumallo=0;
        for(int i=0;i<n;i++){
            if(sumallo+arr[i]>pages){
                cnt++;
                sumallo=arr[i];
                if(sumallo>pages){
                    return false;
                }
            }
            else{
                sumallo+=arr[i];
            }
        }
        if(cnt<=m){
            return true;
        }
        return false;
    }
    int findPages(int arr[], int n, int m) 
    {
        //code here
        sort(arr,arr+n);
        int res=-1;
        int low=arr[0];
        int high=0;
        for(int i=0;i<n;i++){
            high+=arr[i];
        }
        while(low<=high){
            int mid=(low+high)>>1;
            if(isPossible(mid,arr,n,m)){
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

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends