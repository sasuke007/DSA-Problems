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
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<int> input(n);
        for(int i=0;i<n;++i){
            cin>>input[i];
        }
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        vector<int> answer(n);
        for(int i=0;i<n;++i){
            answer[i]=i+1;
        }
        for(int i=0;i<n-1;++i){
            if(input[i]==answer[i]){
                swap(answer[i],answer[i+1]);
            }
        }
        if(input[n-1]==answer[n-1]){
            swap(answer[n-1],answer[n-2]);
        }
        for(int i=0;i<n;++i){
            cout<<answer[i]<<" ";
        }
        cout<<endl;
    }
}

