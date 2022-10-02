#include<bits/stdc++.h>

#define endl "\n"
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int a,b,c;
        cin>>a>>b>>c;
        int first_elevator=abs(a-1);
        int second_elevator=abs(b-c)+abs(c-1);
        if(first_elevator==second_elevator){
            cout<<3<<endl;
        }
        else if(first_elevator<second_elevator){
            cout<<1<<endl;
        }
        else{
            cout<<2<<endl;
        }
    }
}


