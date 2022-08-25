class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;++i){
            int val=nums[i];
            for(int j=i-1;j>=0;--j){
                if(val>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};