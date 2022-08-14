#include <iostream>
#include <unordered_map>
#include <map>
#include<vector>
#include<numeric>
#include <algorithm>
#include<list>
#include<queue>
#include <unordered_set>
#include <cmath>
#include<set>

#define endl "\n"
using namespace std;

vector<vector<int> > find_four_sum(vector<int> &input, int target) {
    vector<vector<int> > quads;
    sort(input.begin(), input.end());
    int n = input.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int new_target = target - (input[i] + input[j]);
            int start=j+1;
            int end=n-1;
            while(start<end){
                if(input[start]+input[end]==new_target){
                    vector<int> quad={input[i],input[j],input[start],input[end]};
                    quads.push_back(quad);
                    ++start;
                }
                else if(input[start]+input[end]>new_target){
                    --end;
                }
                else{
                    ++start;
                }
            }
        }
    }
    return quads;
}

int main() {
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    int target;
    cin >> target;
    vector<vector<int> > quads = find_four_sum(input, target);
    for (vector<int> quad: quads) {
        for (int val: quad) {
            cout << val << " ";
        }
        cout << endl;
    }
}

