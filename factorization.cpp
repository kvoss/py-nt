#include <cmath>

#include "factorization.hpp"

VU
factor(UL n)
{
    VU factors;

    UL limit = sqrtl(n);
    for (UL x = 2;;) {
        if (x > limit) break;

        if (n % x == 0) {
            do {
                n /= x;
                factors.push_back(x);
            } while (n % x == 0);
            limit = sqrtl(n);
        }

        if (x > 2)
            x += 2;
        else
            ++x;
    }
    if (n > 1)
        factors.push_back(n);

    return factors;
}

