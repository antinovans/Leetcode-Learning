class Solution {
public:
    double myPow(double x, int n) {
        long int N = n;
        if(N < 0){
            x = 1/x;
            N = -N;
        }
        return helper(x,N);
    }
    double helper(double x, int n){
        if(n == 0){
            return 1.0;
        }
        double half = helper(x,n*1.0 / 2);
        if(n % 2 == 0){
            return half*half;
        }
        else{
            return half*half*x;
        }
    }
};