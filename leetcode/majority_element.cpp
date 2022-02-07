class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    int candidate_one = INT_MAX, candidate_two = INT_MAX, votes_one = 0,
        votes_two = 0;
    for (int num : nums) {
      if (num == candidate_one) {
        ++votes_one;
      } else if (num == candidate_two) {
        ++votes_two;
      } else if (votes_one == 0) {
        candidate_one = num;
        votes_one = 1;
      } else if (votes_two == 0) {
        candidate_two = num;
        votes_two = 1;
      } else {
        --votes_one;
        --votes_two;
      }
    }
    int freq_one = 0, freq_two = 0;
    for (int num : nums) {
      if (num == candidate_one) {
        ++freq_one;
      }
      if (num == candidate_two) {
        ++freq_two;
      }
    }
    cout << candidate_one << " " << candidate_two << endl;
    int n = nums.size();
    int desired_freq = n / 3 + 1;
    vector<int> ans;
    if (freq_one >= desired_freq) {
      ans.push_back(candidate_one);
    }
    if (freq_two >= desired_freq and candidate_two != candidate_one) {
      ans.push_back(candidate_two);
    }
    return ans;
  }
};