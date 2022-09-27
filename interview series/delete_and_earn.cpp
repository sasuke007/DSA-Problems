class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        vector<pair<int,int> > values;
        for(pair<int,int> p:freq){
            values.push_back(p);
        }
        sort(values.begin(),values.end());
        vector<int> dp(values.size()+1);
        int s=values.size();
        dp[s-1]=values[s-1].first*values[s-1].second;
        for(int i=s-2;i>=0;--i){
            int taken=values[i].first*values[i].second;
            if(values[i].first+1!=values[i+1].first){
                taken+=dp[i+1];
            }
            else{
                taken+=dp[i+2];
            }
            int not_taken=dp[i+1];
            dp[i]=max(taken,not_taken);
        }
        return dp[0];
    }
};