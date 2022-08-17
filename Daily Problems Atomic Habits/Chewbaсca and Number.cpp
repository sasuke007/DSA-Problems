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
string erase_leading_zeros(string number){
    int i=0;
    while(number[i]=='0'){
        number[i]='9';
        ++i;
    }
    return number;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    long long num=n;
    string new_number;
    while(n){
        int digit=n%10;
        n/=10;
        new_number+=char((min(digit,9-digit))+48);
    }
    reverse(new_number.begin(),new_number.end());
    if(new_number[0]=='0'){
        new_number[0]='9';
    }
    cout<<new_number<<endl;
}