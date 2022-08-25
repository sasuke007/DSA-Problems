class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int> > dp(n1+1,vector<int>(n2+1,false));
        for(int i=1;i<dp.size();++i){
            for(int j=1;j<dp[0].size();++j){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n1][n2];
    }
};