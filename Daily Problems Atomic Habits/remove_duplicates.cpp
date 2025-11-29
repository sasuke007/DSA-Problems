class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int i=1,j=1;
            int count = 1;
            for(;j<nums.size();){
                if(nums[j]==nums[j-1]){
                    ++count;
                    if(count>2){
                        ++j;
                        continue;
                    }
                }else{
                    count=1;
                }
                nums[i]=nums[j];
                ++i;
                ++j;
            }
            return i;
        }
};


