class Solution {
private:
    double power(double x, long long n) { // to avoid overflow while doing N = -N range of int ( -2,147,483,648 to 2,147,483,647)
        if (n == 0)
            return 1;

        double half = power(x, n / 2);
        if (n % 2 == 1) {
            return x * half * half;
        } else {
            return half * half;
        }
    }

public:
    double myPow(double x, int n) {
        long long N = n;
        if (n < 0) {
            x = 1 / x;
            N = -N; //making -2,147,483,648 positive cause overflow
        }

        return power(x, N);
    }
};
