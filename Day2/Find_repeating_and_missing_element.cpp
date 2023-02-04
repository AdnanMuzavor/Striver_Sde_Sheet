/*
Problem Statement
Sample Input 1:
1
5
1 3 5 4 4
Sample Output 1:
2 4
Explanation Of Sample Input 1:
As we can clearly see, among all the numbers from 1 to 5, 2 is not present and 4 is occurring twice. Thus, 2 and 4 are missing and repeating numbers respectively.
Sample Input 2:
2
10
4 5 2 9 8 1 1 7 10 3
7
7 5 3 2 1 6 6
Sample Output 2:
6 1
4 6

*/

#include <bits/stdc++.h>
using namespace std;


//O(N)+O(1)
pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Lets under stand what we did
    // REPEATING NUMBER PROCEDURE
    /*1 3 5 4 4
      i
      nums[i]=1, Hence we can visit => nums[abs(nums[i])-1]
                                    => nums[0]
                                    => 1
                                    =>-1
      ___________________________________________________________
     -1 3 5 4 4
        i
      nums[i]=3, Hence we can visit => nums[abs(nums[i])-1]
                                    => nums[2]
                                    => 5
                                    =>-5
      ___________________________________________________________
     -1 3 -5 4 4
          i
      nums[i]=5, Hence we can visit => nums[abs(nums[i])-1]
                                    => nums[4]
                                    => 4
                                    =>-4
      ___________________________________________________________
     -1 3 -5 4 -4
             i
      nums[i]=4, Hence we can visit => nums[abs(nums[i])-1]
                                    => nums[3]
                                    => 4
                                    =>-4
      ___________________________________________________________
     -1 3 -5 -4 -4
                 i
      nums[i]=4, Hence we can visit => nums[abs(nums[i])-1]
                                    => nums[3]
                                    => -4
                                    => ALREADY NEGATIVE
      Since I am able to visit index four(assume 1 indexed) again and again
      it means number 4 is repeating
      CONCLUSION=> nums[i] => 4 is repeating element
    */
    // MISSING NUMBER PROCEDURE
    /*
    -1 3 -5 -4 -4
     i

     arr[i]<0 means i=1 is visitable and hence 1 is not missing
     _____________________________________________________________
     -1 3 -5 -4 -4
        i

     arr[i>0 means i=2 is not visitable and hence value 2 is missing
     _____________________________________________________________
     Hence MISSING ELEMENT=2
    */

    // One number is missing

    // CONCLUSION:
    // While other number has occurred twice
    // Hence w ecan conclude that the repeated number
    // it self has replaced the missing number

    // Hint: array has numbers exactly from 1 to n
    // Hence it's sure that except index given by the number which is missing
    // we will be able to visit all other indices

    // 1)Lets try to find out repeating element
    pair<int, int> op;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        // Visit the c=index position given by current array element
        // And mark it visisted by making value negative
        if (arr[abs(arr[i]) - 1] >= 0)
        {
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
        // Else if index is already visisted it implies that
        // With help of number=nums[i], we are able to visit
        // same index again hence this nums[i] is repeating number
        else
        {
            a = arr[i];
        }
    }

    // Now we have our repeating number
    // And we know that since one number is missing
    // it's sure we wont be able to visit the index
    // corresponding to that number

    // Lets find which index element is positive
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            b = i + 1;
            break;
        }
    }

    // HENCE we have :
    // MISSING element=  2 (b)
    // REPEATING element=4 (a)
    op.first = abs(b);
    op.second = abs(a);

    // return the op
    return op;
}