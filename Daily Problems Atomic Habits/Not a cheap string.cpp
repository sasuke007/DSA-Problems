#include<bits/stdc++.h>

#define endl "\n"
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string input;
        cin >> input;
        int score;
        cin >> score;
        vector<int> freq(26, 0);
        int curr_score = 0;
        for (int i = 0; i < input.size(); ++i) {
            freq[input[i] - 'a']++;
            curr_score += input[i] - 'a' + 1;
        }
        for (int i = 25; i >= 0; --i) {
            while (freq[i] > 0 and curr_score > score) {
                freq[i]--;
                curr_score -= (i + 1);
            }
        }
        string answer;
        for (int i = 0; i < input.size(); ++i) {
            char val = input[i];
            if (freq[val - 'a'] > 0) {
                answer += val;
                freq[val-'a']--;
            }
        }
        cout << answer << endl;
    }
}




