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
        int n;
        cin>>n;
        vector<string> input(n);
        unordered_map<string,int> freq;
        for(int i=0;i<n;++i){
            string val;
            cin>>val;
            input[i]=val;
            freq[val]++;
        }
        string answer="";
        for(int i=0;i<n;++i){
            string val=input[i];
            bool found = false;
            for(int j=1;j<val.size();++j){
                string a=val.substr(0,j);
                string b=val.substr(j,val.size()-j);
                if(freq[a]>0 and freq[b]>0){
                    found=true;
                    break;
                }
            }
            if(found){
                answer+="1";
            }
            else{
                answer+="0";
            }
        }
        cout<<answer<<endl;
    }
}

