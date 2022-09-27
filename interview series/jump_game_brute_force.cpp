class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n);
        dp[n-1]=true;
        for(int i=n-2;i>=0;--i){
            int jump_length=nums[i];
            for(int j=i;j<=i+jump_length and j<n;++j){
                dp[i]=dp[i]|dp[j];
            }
        }
        return dp[0];
    }
};