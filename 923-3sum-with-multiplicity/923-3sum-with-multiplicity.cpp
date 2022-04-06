class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        int no = nums.size();
int carry = 0;
unordered_map<int,int>m;
for(int i=0;i<no;i++){
    for(int j=i+1;j<no;j++){
        carry+=(m[target-nums[i]-nums[j]]);
    }
    m[nums[i]]++;
    carry%=(1000000007);
}
return (carry%1000000007);
}
};