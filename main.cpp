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
int count_inversions(vector<int> &input,int start,int mid,int end){
    int i=start,j=mid+1;
    int inversions=0;
    while(i<=mid && j<=end){
        if(input[i]>2*input[j]){
            inversions+=(mid-i+1);
            ++j;
        }
        else{
            ++i;
        }
    }
    return inversions;
}
int merge(vector<int> &input,int start,int mid,int end){
    int inversions = count_inversions(input,start,mid,end);
    vector<int> merged_array;
    int i=start,j=mid+1;
    while(i<=mid and j<=end){
        if(input[i]<=input[j]){
            merged_array.push_back(input[i]);
            ++i;
        }
        else{
            merged_array.push_back(input[j]);
            ++j;
        }
    }
    while(i<=mid){
        merged_array.push_back(input[i]);
        ++i;
    }
    while(j<=end){
        merged_array.push_back(input[j]);
        ++j;
    }
    int p=start;
    for(int l=0;l< merged_array.size();++l,++p){
        input[p]=merged_array[l];
    }
    return inversions;
}
int merge_sort(vector<int> &input,int start,int end){
    if(start>=end){
        return 0;
    }
    int mid=(start+end)/2;
    int left_inversions = merge_sort(input,start,mid);
    int right_inversions = merge_sort(input,mid+1,end);
    int inversions = merge(input,start,mid,end);
    return left_inversions+right_inversions+inversions;
}

int count_inverse_pairs(vector<int> &input){
    int n=input.size();
    int start=0,end=n-1;
    return merge_sort(input,start,end);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;++i){
        cin>>input[i];
    }
    cout<<count_inverse_pairs(input);
}