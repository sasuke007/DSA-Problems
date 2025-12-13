class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.size();
            int maxPalindromicSubstring = 0;
            int start=0,end=0;
            vector<vector<int> > dp(n,vector<int>(n,0));
            for(int k=0;k<(n+1);++k){
                for(int row=0;row<n;++row){
                    int col = k+row;
                    if(k==0){
                        dp[row][col]=1;
                    }
                    else if(k==1){
                        if(s[row]==s[col]){
                            dp[row][col]=2;
                            if(maxPalindromicSubstring < dp[row][col]){
                                maxPalindromicSubstring = dp[row][col];
                                start = row;
                                end = col;
                            }
                        }
                    }
                    else if(col<n && s[row]==s[col]){
                        if(dp[row+1][col-1]!=0){
                            dp[row][col]=2+dp[row+1][col-1];
                        }
                        if(maxPalindromicSubstring < dp[row][col]){
                            maxPalindromicSubstring = dp[row][col];
                            start = row;
                            end = col;
                        }
                    }
                }
            }
            // for(int i=0;i<n;++i){
            //     for(int j=0;j<n;++j){
            //         cout<<dp[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            return s.substr(start,end-start+1);
        }
    };