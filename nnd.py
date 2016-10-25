# coding: utf-8
from collections import defaultdict
import factors as fs


class NthNumbersDistribution(object):
    """
    TODO: memoize, persist
    """
    def __init__(self, n):
        """
        ..note:: does not include the number n
        """
        self.ffs = [fs.factor(x) for x in xrange(n)]

    def max_factorization_len(self):
        """
        >>> max_factorization_len([[2], [3], [2, 2], [5], [2, 3]])
        2
        """
        max_factorization_len = max(len(fs) for fs in self.ffs)
        return max_factorization_len

    def longest_factorizations(self):
        """
        >>> longest_factorizations([[2], [3], [2, 2], [5], [2, 3]])
        [[2, 2], [2, 3]]
        """
        max_len = self.max_factorization_len()
        lfs = list(fs for fs in self.ffs
                      if len(fs) == max_len)
        return lfs

    def nth_nr_dist(self):
        """
        how many number do we have that have 1 factor, 2 factors, and so on

        for [[2], [3], [2, 2], [5], [2, 3]] we have
        0: **
        1: ***
        2: **
        0 and 1 have 0 factors
        there are 3 prime numbers in

        """
        cntr = defaultdict(int)
        lffs = map(len, self.ffs)
        for l in lffs:
            cntr[l] += 1
        return cntr

    def nth_nrs(self, nth):
        """
        what numbers have exactly n factors?
        """
        nnrs = []
        for fs in self.nth_factors(nth):
            product = reduce(lambda a, b: a * b, fs, 1)
            nnrs.append(product)
        return nnrs

    def nth_factors(self, nth):
        """
        what factorizations of lenght n do we have
        """
        nfs = [fs for fs in self.ffs if len(fs) == nth]
        return nfs

if __name__ == '__main__':
    nn = NthNumbersDistribution(2093)
    print '---- NthNumbersDistribution(2093)'
    print '----'

    print 'numbers with 8 factors:', nn.nth_nrs(8)
    print 'factorizations of len 8:', nn.nth_factors(8)
    print 'lentgh of the longest factorization:', nn.max_factorization_len()
    print 'the longest factorization:', nn.longest_factorizations()
    print 'distribution of factorization lengths: ', dict(nn.nth_nr_dist())

    print '----'

