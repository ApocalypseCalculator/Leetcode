// 1137. N-th Tribonacci Number

// fast solution
// strat: use closed form for the linear recurrence

#include <cmath>
class Solution {
    double a = (std::cbrt(19 + 3 * std::sqrt(33)) + std::cbrt(19 - 3 * std::sqrt(33)) + 1)/3;
    double b = std::cbrt(586 + 102 * std::sqrt(33));
    double t = 3*b/(b*b - 2*b + 4);
public:
    int tribonacci(int n) {
        return std::round(t*std::pow(a,n));
    }
};