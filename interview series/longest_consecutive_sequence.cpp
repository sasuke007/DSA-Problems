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
int longest_consecutive_sequence(vector<int> &input){
    int n=input.size();
    unordered_set<int> elements(input.begin(),input.end());
    int longest_sequence = 1;
    for(int elem:input){
        if(elements.find(elem+1)==elements.end()){
            int temp_longest_sequence=0;
            while(elements.find(elem)!=elements.end()){
                ++temp_longest_sequence;
                --elem;
            }
            longest_sequence=max(longest_sequence,temp_longest_sequence);
        }
    }
    return longest_sequence;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;++i){
        cin>>input[i];
    }
    cout<<longest_consecutive_sequence(input);
}