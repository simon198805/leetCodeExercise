#include <include.hpp>
/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
    double mypow2(double x, int n)
    {
        //cout << n;
        if(n == 1) return x;
        double val = mypow2(x, n/2);
        return val * val * (n % 2 == 1? x:1);
    }
public:
    double myPow(double x, int n) {
        if(x == 1) return 1;
        if(x == -1) return n%2 == 0? 1:-1;
        if(n == 0) return 1;
        double res = 1;
        // min value will cause problem when truning to postive num
        if(n == INT32_MIN) return 0;
        res = mypow2(x, abs(n));
        if(n < 0) res = 1.0/res;
        return res;
    }
};
// @lc code=end

