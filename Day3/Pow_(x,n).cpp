/*
50. Pow(x, n)
Medium

5506

6149

Add to List

Share
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).



Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/

#include <bits/stdc++.h>
using namespace std;

// O(N)+O(1)
class Solution
{
public:
    double myPow(double x, int n)
    {

        double ans = 1.00000;

        // If n is positive simply multiply (x) n times
        if (n >= 0)
        {
            while (n--)
                ans = ans * x;
        }
        // if n is negative simple divide x n times
        else
        {
            n = abs(n);
            while (n--)
                ans = ans / x;
        }
        // return the answer
        return ans;
    }
};

// Good way of writing code

class Solution
{
public:
    double myPow(double x, int n)
    {
        int neg = 0;
        if (n < 0)
            neg = 1;
        double ans = 1.00000;

        // As we use n for looping
        n = abs(n);

        // find x^n

        while (n--)
            ans = ans * x;

        // return the answer
        // if neg=1 means we are suppose to find 1/x^n as n<0
        // else we return ans
        return neg ? (1 / ans) : ans;
    }
};

// O(logn) as we are dividing number by 2
// O(1) space

class Solution
{
public:
    double myPow(double x, int n)
    {
        // STRONGLE RECOMMENDED TO WATCH THE VIDEO

        /*
        _________________________________________________________________
         2^10  x=2  nn=10

         10%2==0 |  x=x*x => x=2*2 => x=4   | nn=nn/2  => 10/2 => 5
         5%2!=0  |  a=a*x => a=1*4 => a=4   | nn=nn-1  => 5-1  => 4
         4%2==0  |  x=x*x => x=4*4 => x=16  | nn=nn/2  => 4/2  => 2
         2%2==0  |  x=x*x => x=16*16=>x=256 | nn=nn/2  => 2/2  => 1
         1%2!=0  |  a=a*x => a=5*256=>a=1024| nn=nn-1  => 1-1  => 0 //STOP

         HENCE ANSWER IS: 1024





        _________________________________________________________________

        */

        // Subs 256 in above cases

        // initialise the answer
        double ans = 1.00000;

        // preserve the n
        long long nn = n;

        // make it positive as negative case will be handled later
        if (nn < 0)
            nn = nn * -1;

        // Folllow the procedure
        while (nn)
        {
            if (nn % 2 == 0)
            {
                x = x * x;
                nn = nn / 2;
            }
            else
            {
                ans = ans * x;
                nn = nn - 1;
            }
        }

        // return ans based on n
        if (n < 0)
            ans = 1.00000 / double(ans);
        return ans;
    }
};