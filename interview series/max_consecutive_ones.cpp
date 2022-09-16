class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=-1,j=0;
        int max_ones=0;
        int n=nums.size();
        while(j<n){
            int val=nums[j];
            if(val!=1){
                max_ones=max(max_ones,j-i-1);
                i=j;
            }
            ++j;
        }
        max_ones=max(max_ones,j-i-1);
        return max_ones;
    }
};