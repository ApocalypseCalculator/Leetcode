// 279. Perfect Squares

// strat: DP!!

#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    int solve(int n, int* memo) {
        if(memo[n] != -1) {
            return memo[n];
        }
        int maxval = floor(sqrt(n));
        int minval = n;
        for(int i = maxval; i > 0; i--) {
            int sqrs = 1 + solve(n - i*i, memo);
            if(sqrs < minval) minval = sqrs;
        }
        memo[n] = minval;
        return minval;
    }
    int numSquares(int n) {
        int *memo = new int[n+1];
        fill(memo, memo + n+1, -1);
        memo[0] = 0;
        memo[1] = 1;
        int result = solve(n, memo);
        delete[] memo;
        return result;
    }
};