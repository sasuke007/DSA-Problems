vector<int> compute_left_max(const vector<int> &A){
    int n=A.size();
    vector<int> left_max(n);
    left_max[0]=A[0];
    for(int i=1;i<n;++i){
        left_max[i]=max(left_max[i-1],A[i]);
    }
    return left_max;
}
vector<int> compute_right_max(const vector<int> &A){
    int n=A.size();
    vector<int> right_max(n);
    right_max[n-1]=A[n-1];
    for(int i=n-2;i>=0;--i){
        right_max[i]=max(right_max[i+1],A[i]);
    }
    return right_max;
}
void print(vector<int> &num){
    for(int i=0;i<num.size();++i){
        cout<<num[i]<<" ";
    }
    cout<<endl;
}
int Solution::trap(const vector<int> &A) {
    int n=A.size();
    vector<int> left,right;
    int answer=0;
    left=compute_left_max(A);
    right=compute_right_max(A);
    //print(left);
    //print(right);
    for(int i=0;i<n;++i){
        answer+=min(left[i],right[i])-A[i];
    }
    return answer;
}
