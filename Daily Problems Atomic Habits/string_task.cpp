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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string input;
    cin>>input;
    string answer;
    set<char> vowels={'A', 'O', 'Y', 'E', 'U', 'I','a','o','y','e','u','i'};
    for(int i=0;i<input.size();++i){
        char alphabet = input[i];
        if(vowels.find(alphabet)!=vowels.end()){
            continue;
        }
        else if('A'<=alphabet and alphabet<='Z'){
            answer+='.';
            answer+=(alphabet+32);
        }
        else{
            answer+='.';
            answer+=alphabet;
        }
    }
    cout<<answer<<endl;
}