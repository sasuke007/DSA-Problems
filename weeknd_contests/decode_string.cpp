#include<bits/stdc++.h>

#define endl "\n"
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin>>n;
        string t;
        cin>>t;
        string answer;
        for(int i=n-1;i>=0;){
            if(t[i]=='0'){
                int num=(t[i-2]-'0')*10+(t[i-1]-'0');
                answer+=('a'+(num-1));
                i-=3;
            }
            else{
                int num=(t[i]-'0');
                answer+=('a'+(num-1));
                i--;
            }
        }
        reverse(answer.begin(),answer.end());
        cout<<answer<<endl;
    }
}



