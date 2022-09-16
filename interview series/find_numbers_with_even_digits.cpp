class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even_digits=0;
        for(int i=0;i<nums.size();++i){
            int count =0;
            int val=nums[i];
            while(val){
                ++count;
                val/=10;
            }
            if(count%2==0){
                ++even_digits;
            }
        }
        return even_digits;
    }
};