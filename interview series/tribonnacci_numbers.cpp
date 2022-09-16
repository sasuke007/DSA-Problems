class Solution {
public:
    int tribonacci(int n) {
        int t_0=0;
        int t_1=1;
        int t_2=1;
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 1;
        }
        int i=3;
        while(i<=n){
            int temp=t_0+t_1+t_2;
            t_0=t_1;
            t_1=t_2;
            t_2=temp;
            ++i;
        }
        return t_2;
    }
};