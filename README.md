# py-nt

The prime numbers have only 1 factor, the secondary numbers have 2 factors, and so on.
Get distribution of number of factors for a given range of numbers.

For example

    $ python nnd.py
    ---- NthNumbersDistribution(2093)
    ----
    numbers with 8 factors: [256, 384, 576, 640, 864, 896, 960, 1296, 1344, 1408, 1440, 1600, 1664, 1944, 2016]
    factorizations of len 8: [[2, 2, 2, 2, 2, 2, 2, 2], [2, 2, 2, 2, 2, 2, 2, 3], [2, 2, 2, 2, 2, 2, 3, 3], [2, 2, 2, 2, 2, 2, 2, 5], [2, 2, 2, 2, 2, 3, 3, 3], [2, 2, 2, 2, 2, 2, 2, 7], [2, 2, 2, 2, 2, 2, 3, 5], [2, 2, 2, 2, 3, 3, 3, 3], [2, 2, 2, 2, 2, 2, 3, 7], [2, 2, 2, 2, 2, 2, 2, 11], [2, 2, 2, 2, 2, 3, 3, 5], [2, 2, 2, 2, 2, 2, 5, 5], [2, 2, 2, 2, 2, 2, 2, 13], [2, 2, 2, 3, 3, 3, 3, 3], [2, 2, 2, 2, 2, 3, 3, 7]]
    lentgh of the longest factorization: 11
    the longest factorization: [[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]]
    distribution of factorization lengths:  {0: 2, 1: 316, 2: 598, 3: 527, 4: 331, 5: 172, 6: 84, 7: 38, 8: 15, 9: 7, 10: 2, 11: 1}
    ----

