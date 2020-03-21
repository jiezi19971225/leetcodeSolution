/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        int res = 0;
        if (n <= 2)
        {
            return res;
        }
        int prime[2000000];
        fill(prime, prime + 2000000, 1);
        for (int i = 2; i < n; ++i)
        {
            if (prime[i])
            {
                res++;
            }
            for (int j = i * 2; j < n; j += i)
            {
                prime[j] = 0;
            }
        }
        return res;
    }
};
// @lc code=end
