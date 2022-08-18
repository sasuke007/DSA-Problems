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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> input(3);
    for(int i=0;i<3;++i){
        cin>>input[i];
    }
    sort(input.begin(),input.end());
    cout<<(input[1]-input[0])+(input[2]-input[1])<<endl;
}