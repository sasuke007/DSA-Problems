
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int> > dp(2,vector<int>(n+1,0));
        int maximum=nums[0];
        dp[0][1]=max(0,nums[0]);
        dp[1][1]=min(0,nums[0]);
        for(int i=2;i<n+1;++i){
            int val=nums[i-1];
            if(val>=0){
                dp[0][i]=max(val,val*dp[0][i-1]);
                dp[1][i]=min(val,val*dp[1][i-1]);
            }
            else{
                dp[0][i]=max(val,val*dp[1][i-1]);
                dp[1][i]=min(val,val*dp[0][i-1]);
            }
            maximum=max(maximum,max(dp[0][i],dp[1][i]));
        }
        for(int i=0;i<dp.size();++i){
            for(int j=0;j<dp[0].size();++j){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return maximum;
    }

};