class Solution {
public:
    double myPow(double x, int n) {
        double N = n;  // To safely handle INT_MIN

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return power(x, N);
    }

private:
    double power(double x, long long n) {
        if (n == 0) return 1;
        double half = power(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};
