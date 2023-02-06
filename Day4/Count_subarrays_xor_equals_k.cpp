/*
Subarray with given XOR
Bookmark
Medium
40.3% Success
493
8
Asked In:
Dunzo
Problem Description



Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.



Problem Constraints
1 <= length of the array <= 105

1 <= A[i], B <= 109



Input Format
The first argument given is the integer array A.

The second argument given is integer B.



Output Format
Return the total number of subarrays having bitwise XOR equals to B.



Example Input
Input 1:

 A = [4, 2, 2, 6, 4]
 B = 6
Input 2:

 A = [5, 6, 7, 8, 9]
 B = 5


Example Output
Output 1:

 4
Output 2:

 2


Example Explanation
Explanation 1:

 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Explanation 2:

 The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]


*/

#include <bits/stdc++.h>
using namespace std;
// O(N^2)
// O(1)

int subarraysXor(vector<int> &arr, int x)
{

    // Lets try brute force
    // 1)Take each subarray
    // 2)Check if it's xor equals k
    // 3)If so increment counter

    /*
        1   2   3   4
        i
        j                      ->Take xor with itelf and compare
        i   j                  ->Add xor of next elemnt and compare
        i       j              ->Add xor of next elemnt and compare
        i           j          ->Add xor of next elemnt and compare

       => i++, xor=0 <=

        1   2   3   4
            i
            j                      ->Take xor with itelf and compare
            i   j                  ->Add xor of next elemnt and compare
            i       j              ->Add xor of next elemnt and compare

       => i++, xor=0 <=

           1   2   3   4
               i
               j                      ->Take xor with itelf and compare
               i   j                  ->Add xor of next elemnt and compare
               i       j              ->Add xor of next elemnt and compare

         => i++, xor=0 <=

         and so on

    */

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int xor_sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            xor_sum = xor_sum ^ arr[j];
            if (xor_sum == x)
                count++;
        }
    }
    return count;
}

// TC -> O(NLOGN) Because map in worst case takes TC of LogN
//       if unordered map was used, worst case TC is O(N) hence Tc could be
//       O(N^2)
// SC -> O(N)

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    // Optimise approch
    // 1) We can use kadane's algorithm
    // 2)A frequncy array i.e map of xor values and indices of occurence

    /*
    LETS UNDERSTAND THE APPROACH
    => say from range i to j we have xor_value= xr1

     i___________xr1____________j

    => we can divide the xr1 into values say xr11 and xr12

    i___________xr1____________j
         xr11           xr12

    =>From this it's clear that xr1=xr11^xr12

    =>Now if you noice, if we count the occurence of xr11,
      won't it tell the occurence of xr22?

    =>It can be this:

    i_________________xr1_______j
         xr11              xr12

    =>It can be this:

    i______xr1________________________j
      xr11              xr12

    =>Hence if we know the occurence of xr11 can tell occurence of xr22

    =>Lets apply this concept here:

    let xr11 be some value and xr12 be the => x <= we are given

      i__________xr1________________________j
           xr11              x

    =>  xr1 = xr11 ^ x
    => xr11 = xr1 ^ x

    => Hence if we know the count of occurence of xr11
    => We can say that it tells the occurnce of xor_val = x
    => as well at the same time
    =>Hence we add the count of xr11 to count value

    DRY RUN
    4 2 2 6 4
    i
    xor=0    map=[(prefix_xor,count)]  x=6 count=0

    START at i=0
    ______________________________________________________________
    4 2 2 6 4
    i

    xor= xor ^ 4 = 0 ^ 4 = 4

    1) Subraay wityh xor_val = x from start
    4!=x   =>   4!=6   =>   count = 0

    2)find xr11:

    Hence xr1 = xr11 ^ x           0100
          xr11 = xr1 ^ x          ^0110
          xr11 = 4 ^ 6             0010
          xr11 = 2
    mp[2] doesnt exists => no change in count

          i__________xr1=4________________________j
            xr11=2              x=6

          conclusion: No occurence of 2, hence no occurence of 6 as well

    3)mp[curr_xor_value] exists?
    mp[4] exists? no. Hence mp[4] = 1  => xor_value 4 appears once in array

    mp => [(4,1)]

    4)i++
    ___________________________________________________________________
    4 2 2 6 4
      i

    xor= xor ^ 2 = 4 ^ 2 = 6

    1) Subraay wityh xor_val = x from start
    6==x   =>   6==6   =>   count = 1

    2)find xr11:
    Hence xr1 = xr11 ^ x           0110
          xr11 = xr1 ^ x          ^0110
          xr11 = 6 ^ 6             0000
          xr11 = 0
    mp[0] doesnt exists => no change in count


          i__________xr1=6________________________j
            xr11=0              x=6

          conclusion: No occurence of 0, hence no occurence of 6 as well

    3) mp[curr_xor_value] exists?
    mp[6] exists? no. Hence mp[6] = 1  => xor_value 6 appears once in array

    mp => [(4,1) (6,1)]

    4)i++
    _____________________________________________________________________
    4 2 2 6 4
        i

    xor= xor ^ 2 = 6 ^ 2 = 4

    1) Subraay wityh xor_val = x from start
    4==x   =>   4!=6   =>   count = 1 (no change)

    2)find xr11:
    Hence xr1 = xr11 ^ x           0100
          xr11 = xr1 ^ x          ^0110
          xr11 = 4 ^ 6             0010
          xr11 = 2
    mp[2] does not exists => no change in count


          i__________xr1=4________________________j
            xr11=2              x=6

          conclusion: No occurence of 2, hence no occurence of 6 as well

    3) mp[curr_xor_value] exists?
    mp[4] exists? yes. Hence mp[4] ++  => xor_value 4 appears twice in array

    mp => [(4,2) (6,1)]

    4)i++
    _____________________________________________________________________
    4 2 2 6 4
          i

    xor= xor ^ 2 = 4 ^ 6 = 2

    1) Subraay wityh xor_val = x from start
    2==x   =>   2!=6   =>   count = 1 (no change)

    2)find xr11:
    Hence xr1 = xr11 ^ x           0010
          xr11 = xr1 ^ x          ^0110
          xr11 = 2 ^ 6             0100
          xr11 = 4
    mp[4] does exists => count + mp[4]
                      => 1 + 2
                      => 3


          i__________xr1=2________________________j
            xr11=4              x=6

          conclusion: xor_val 4 apperas twice hence xor_val 6 also
                      appeared twice

    3) mp[curr_xor_value] exists?
    mp[2] exists? no. Hence mp[2] = 1  => xor_value 2 appears once in array

    mp => [(4,2) (6,1),(2,1)]

    4)i++
    _________________________________________________________________
     4 2 2 6 4
             i

    xor= xor ^ 2 = 2 ^ 4 = 6

    1) Subraay wityh xor_val = x from start
    6==x   =>   6==6   =>   count = 4 (++)

    2)find xr11:
    Hence xr1 = xr11 ^ x           0100
          xr11 = xr1 ^ x          ^0110
          xr11 = 6 ^ 6             0010
          xr11 = 0
    mp[0] does not exists


          i__________xr1=6________________________j
            xr11=0              x=6

          conclusion: xor_val 0 apperas 0 times hence xor_val 6 also
                      appears 0 times correspondingly

    3) mp[curr_xor_value] exists?
    mp[6] exists? yes. Hence mp[6] = ++  => xor_value 6 appears twice in array

    mp => [(4,2) (6,2),(2,1)]

    4)i++
    //STOP
    _______________________________________________________________
    => ANS=4
    Subarrays:
    1)[4 2]
    2)        ________xr=2________
               4    2    2    6
              ____ ______________
              xr1=4   x=6
        [2 2 6]
    3)      ________xr=2________
               4    2    2    6
            ______________   ___
              xr1=4          x=6
        [6]
     4)  [4 2 2 6 4]  xor=6
    */
    int count = 0;
    map<int, int> mp;
    int xor_val = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        // Fidn xor value
        xor_val = xor_val ^ arr[i];
        // if xir value is equal to x we wanted
        if (xor_val == x)
            count++;
        // Find xr11 value
        int xr11 = xor_val ^ x;
        // Check if xr11 exist,
        // if it exists, it marks existance of x as well
        // that many times
        if (mp.count(xr11))
            count += mp[xr11];
        // Add current xor value into map
        // or increment it if it exists
        mp[xor_val]++;
    }
    return count;
}