// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<long long> presum;
        long long curr_sum=0;
        int st=0,end=1;
        for(int i=0;i<n;i++){
            if(s==0 && arr[i]==0){
                return {i+1,i+1};
            }
            curr_sum+=arr[i];
            if(curr_sum==s){
                return {1,i+1};
            }
            presum.push_back(curr_sum);
        }
        if(s==0){
            return {-1};
        }
        curr_sum=arr[0];
        if(curr_sum==s){
            return {1,1};
        }
        while(st<=end && end<n){
            curr_sum=presum[end]-presum[st];
            if(curr_sum==s){
                return {st+2,end+1};
            }
            else if(curr_sum<s){
                end++;
            }
            else{
                st++;
            }
        }
        return {-1};
        
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends