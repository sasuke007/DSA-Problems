#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    int tc;
    cin>>tc;
    while(tc--){
        long long n,m;
        cin>>n>>m;
        cout<<(m*(m+1))/2 + m*(n*(n+1)/2) - m<<endl;
    }
}




