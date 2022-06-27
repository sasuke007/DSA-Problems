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
        if(n%2!=0){
            cout<<"Mike"<<endl;
        }
        else{
            int minimum = *min_element(input.begin(),input.end());
            int index = find(input.begin(),input.end(),minimum) - input.begin();
            if(index%2==0){
                cout<<"Joe"<<endl;
            }
            else{
                cout<<"Mike"<<endl;
            }
        }
    }
}

