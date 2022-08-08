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

void generate_permutations(vector<int> &input, int index, unordered_set<int> &present, vector<int> &new_permutation) {
    int n = input.size();
    if (index >= n) {
        for(int i=0;i<n;++i){
            cout<<new_permutation[i]<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i < input.size(); ++i) {
        int val = input[i];
        if (present.find(i) == present.end()) {
            present.insert(i);
            new_permutation[index]=val;
            generate_permutations(input, index + 1, present, new_permutation);
            present.erase(i);
        }
    }
}

int main() {
    vector<int> input = {1, 2, 3, 4, 5};
    unordered_set<int> present;
    int n=input.size();
    vector<int> new_permutation(n);
    generate_permutations(input, 0, present, new_permutation);
}

