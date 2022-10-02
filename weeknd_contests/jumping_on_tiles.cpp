#include<bits/stdc++.h>

#define endl "\n"
using namespace std;
bool check(char ch,char start,char end){
    if(start>=end){
        return ch>=end and ch<=start;
    }
    else{
        return ch>=start and ch<=end;
    }
}
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        int n = s.size();
        int cost = abs(s[0] - s[n - 1]);
        int jumps=0;
        unordered_map<char,vector<int> > freq;
        for(int i=0;i<n;++i){
            char ch=s[i];
            if(check(ch,s[0],s[n-1])){
                freq[ch].push_back(i);
                ++jumps;
            }
        }
        cout<<cost<<" "<<jumps<<endl;
        if(s[0]>=s[n-1]){
            for(char ch=s[0];ch>=s[n-1];--ch){
                for(int j=0;j<freq[ch].size();++j){
                    cout<<freq[ch][j]+1<<" ";
                }
            }
        }
        else{
            for(char ch=s[0];ch<=s[n-1];++ch){
                for(int j=0;j<freq[ch].size();++j){
                    cout<<freq[ch][j]+1<<" ";
                }
            }
        }
        cout<<endl;
    }
}

