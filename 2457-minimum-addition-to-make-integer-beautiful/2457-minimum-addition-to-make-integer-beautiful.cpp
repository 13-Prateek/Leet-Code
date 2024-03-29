class Solution {
public:
    int sumDigits(long long n) {
        int res = 0;
        for (; n; n /= 10)
            res += n % 10;
        return res;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long res = 0, mul = 1;
        for (; sumDigits(n) > target; mul *= 10) {
            res += mul * ((10 - n % 10) % 10);
            n = (n + (10 - n % 10) % 10) / 10;       
        }
        return res;
    }
};