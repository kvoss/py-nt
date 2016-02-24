# coding: utf-8
from collections import defaultdict
import factors as fs


class NthNumbersDistribution(object):
    def __init__(self, n):
        self.ffs = [fs.factor(x) for x in xrange(n)]

    def max_factorization_len(self):
        max_factorization_len = max(len(fs) for fs in self.ffs)
        return max_factorization_len

    def longest_factorizations(self):
        lfs = list(fs for fs in self.ffs
                      if len(fs) == self.max_factorization_len())
        return lfs

    def nth_nr_dist(self):
        cntr = defaultdict(int)
        lffs = map(len, self.ffs)
        for l in lffs:
            cntr[l] += 1
        return cntr

    def nth_nrs(self, nth):
        nnrs = []
        for fs in self.nth_factors(nth):
            product = reduce(lambda a, b: a * b, fs, 1)
            nnrs.append(product)
        return nnrs

    def nth_factors(self, nth):
        nfs = [fs for fs in self.ffs if len(fs) == nth]
        return nfs

