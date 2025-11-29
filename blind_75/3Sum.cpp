class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            set<vector<int>> answer;
            sort(nums.begin(),nums.end());
            int n=nums.size();
            for(int i=0;i<nums.size();++i){
                int j=i+1;
                int k=nums.size()-1;
                int target=-nums[i];
                while(j<k){
                    int temp = nums[j]+nums[k];
                    if(temp==target){
                        answer.insert({nums[i],nums[j],nums[k]});
                        ++j;
                    }
                    else if(temp>target){
                        --k;
                    }
                    else{
                        ++j;
                    }
                }
            }
            return vector<vector<int>>(answer.begin(),answer.end());
        }
    };


    // https://leetcode.com/problems/3sum/


    