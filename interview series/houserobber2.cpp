class Solution {
public:
    int dhoom2(vector<int> &nums,int start,int end){
        vector<int> dp(end-start+1);
        int n=dp.size();
        dp[n-1]=nums[end];
        dp[n-2]=max(nums[end],nums[end-1]);
        for(int i=n-3,j=end-2;i>=0;--i,--j){
            dp[i]=max(nums[j]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        return max(dhoom2(nums,0,n-2),dhoom2(nums,1,n-1));
    }
};