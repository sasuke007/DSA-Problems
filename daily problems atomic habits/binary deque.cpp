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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,s;
        cin>>n>>s;
        vector<int> input(n);
        for(int i=0;i<n;++i){
            cin>>input[i];
        }
        int total_ones= accumulate(input.begin(),input.end(),0);
        vector<int> first,last;
        for(int i=0;i<n;++i){
            if(input[i]==1){
                first.push_back(i);
            }
        }
        for(int i=n-1;i>=0;--i){
            if(input[i]==1){
                last.push_back(i);
            }
        }
        if(total_ones<s){
            cout<<-1<<endl;
        }
        else if(total_ones==s){
            cout<<0<<endl;
        }
        else{
            int remove_ones=total_ones-s;
            int answer=min((n-last[remove_ones-1]),(first[remove_ones-1]+1));
            for(int i=1;i<=(total_ones-s);++i){
                int left_index=first[i-1];
                int right_index=last[(total_ones-s)-i-1];
                answer=min(answer,(left_index+1)+(n-right_index));
            }
            cout<<answer<<endl;
        }
    }
}

