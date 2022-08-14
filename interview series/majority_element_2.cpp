class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int votes1=0;
        int votes2=0;
        int candidate1=-1;
        int candidate2=-1;
        for(int num:nums){
            if(num==candidate1){
                ++votes1;
            }
            else if(num==candidate2){
                ++votes2;
            }
            else if(votes1==0){
                candidate1=num;
                ++votes1;
            }
            else if(votes2==0){
                candidate2=num;
                ++votes2;
            }
            else{
                --votes1;
                --votes2;
            }
        }
        int candidate1_freq=0;
        int candidate2_freq=0;
        for(int num:nums){
            if(num==candidate1){
                ++candidate1_freq;
            }
            if(num==candidate2){
                ++candidate2_freq;
            }
        }
        cout<<candidate1<<" "<<candidate2<<endl;
        int desired_freq=nums.size()/3;
        vector<int> answer;
        if(candidate1_freq>desired_freq){
            answer.push_back(candidate1);
        }
        if(candidate2_freq>desired_freq and candidate2!=candidate1){
            answer.push_back(candidate2);
        }
        return answer;
    }
};//
// Created by Sasuke on 8/14/2022.
//
