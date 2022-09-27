#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &input,int target){
	int n=input.size();
	int count=0;
	for(int i=1;i<n;++i){
		input[i]=input[i]+input[i-1];
	}
	unordered_map<int,int> present;
	present.insert({0,1});
	for(int i=0;i<n;++i){
		int x=input[i];
		int y=x-target;
		auto elem = present.find(y);
		if(elem!=present.end()){
			count+=elem->second;
		}
		present[x]++;
	}
	return count;
}
int main(){
	int n;
	cin>>n;
	vector<int> input(n);
	for(int i=0;i<n;++i){
		cin>>input[i];
	}
	int target;
	cin>>target;
	cout<<solve(input,target)<<endl;
}


