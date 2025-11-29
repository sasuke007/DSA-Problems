class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int count =0;
            int current=-1;
            for(int i=0;i<nums.size();++i){
                if(count==0){
                    current=nums[i];
                    count=1;
                    continue;
                }            
                if(nums[i]==current){
                    ++count;
                }else{
                    --count;
                }
            }
            return current;
        }
};
