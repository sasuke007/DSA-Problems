class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        int n=nums.size();
        bitset<10007> dp;
        dp.set(0,true);
        for(int i=0;i<n;++i){
            int val=nums[i];
            dp|=(dp<<val);
        }
        return dp[target];
    }
};