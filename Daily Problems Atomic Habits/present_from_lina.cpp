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
void print_line(int n,int spaces){
    for(int i=0;i<2*spaces;++i){
        cout<<" ";
    }
    if(n==0){
        cout<<0<<endl;
        return;
    }
    for(int i=0;i<=n;++i){
        cout<<i<<" ";
    }
    for(int i=n-1;i>=0;--i){
        if(i!=0){
            cout<<i<<" ";
        }
        else{
            cout<<i;
        }
    }
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<=n;++i){
        print_line(i,n-i);
    }
    for(int i=n-1;i>=0;--i){
        print_line(i,n-i);
    }
}