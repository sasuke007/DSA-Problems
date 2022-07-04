#include<bits/stdc++.h>

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
        int r = 0;
        bool shuffling_exists=true;
        vector<int> shuffle(n);
        for(int i=0;i<n;++i){
            shuffle[i]=i+1;
        }
        while(r<n){
            int l=r;
            int count =0;
            while(l < n - 1 and input[l] == input[l + 1]){
                ++count;
                ++l;
            }
            if(l==r){
                shuffling_exists=false;
                break;
            }
            else{
                rotate(shuffle.begin()+r,shuffle.begin()+r+1,shuffle.begin()+l+1);
            }
            r=l+1;
        }
        if(shuffling_exists){
            for(auto &val:shuffle){
                cout<<val<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}




