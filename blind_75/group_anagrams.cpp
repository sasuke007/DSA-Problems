class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> sorted;
    for (string str : strs) {
      string temp = str;
      sort(temp.begin(), temp.end());
      sorted[temp].push_back(str);
    }
    vector<vector<string>> answer;
    for (auto &elem : sorted) {
      answer.push_back(move(elem.second));
    }
    return answer;
  }
};

// https://leetcode.com/problems/group-anagrams/