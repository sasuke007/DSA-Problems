class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        int n=nums.size();
        vector<vector<bool> > dp(n+1,vector<bool>(target+1,0));
        for(int i=0;i<dp.size();++i){
            dp[i][0]=true;
        }
        for(int i=1;i<dp.size();++i){
            for(int j=0;j<dp[0].size();++j){
                int val=nums[i-1];
                dp[i][j]=(j-val>=0?dp[i-1][j-val]:false)or(dp[i-1][j]);
            }
        }
        return dp[n][target];
    }
};