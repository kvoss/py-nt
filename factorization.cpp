#include <cmath>

#include "factorization.hpp"

VU
factor(UL n)
{
    VU factors;

    UL limit = sqrtl(n);
    for (UL x = 2;; ++x) {
        if (x > limit) break;

        while (n % x == 0) {
            n /= x;
            limit = sqrtl(n);
            factors.push_back(x);
        }
    }
    if (n > 1)
        factors.push_back(n);

    return factors;
}

