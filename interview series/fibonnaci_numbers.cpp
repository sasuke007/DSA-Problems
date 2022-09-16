class Solution {
public:
    int fib(int n) {
        int first=0;
        int second=1;
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return second;
        }
        int i=2;
        while(i<=n){
            int temp=first+second;
            first=second;
            second=temp;
            ++i;
        }

        return second;
    }
};