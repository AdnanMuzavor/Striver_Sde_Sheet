# Striver_Sde_Sheet
Striver SDE sheet is helpful sheet for approaching to a valid solution to a problem.

## Day 1
- Approaches:  Sliding window
- Algorithms: Kadane Algorithm, Next permutation algorithm 

## Day 2
- Approaches: Negative indexing values of array to find repeating and missing
- Algorithms: Merge sort and it's use to count inversions
- Special   : Finding duplicate using linkedlist appraoch given array of [1,n] elements.

## Day 3
- Approaches : Apply merge sort to find count of next smaller elements, count reverse pairs etc.
- Algorithms : Voting Moore Algorithm to find majority element.

## Day 4
### Approaches  
- reducing 4 sum from  O(N^4) to O(N^3logN) to O(N^2logN) by sorting, 
- using map to find unique pair making up given sum.
- largest subarray with sum 0 using map and concept of repeating sum
- largest consecutive sequence in array using Sorting and Map approach.
- learnt xor technique to find count(sub-arrays) with given xor.


## Day 5
- Approaches : slow-fast pointer approach to find middle, delete last nth node
- Algorithm : recursive merge sort to merge to sorted linkedlist.

## Day 6
### Approaches: 
- tracking cycle,find node cycled using slow/fast pointer.
- flattening the linkedlist using merge sort and recursion.
- intersection of two LL using equi distancing.
- checking palindrome using vector, manipulating LL.
- reversing nodes in k groups using proper pointer linking.

## Day 7
### Approaches: copy LL with random pointer [map + LL manip approach].
- rotate LL simply by pointer manip and k%len logic.
- use pointers to find max consecutive ones and removing duplicates.
- trapping rain water by keeping track of tallest walls around and selecting min among them.   

## Day 8
### Approaches: 
- Greedy approach by sorting to maximise/minimise th result
- Using greedy technique to find tracks needed, maximum meeting feeting in room etc

## Day 9
### Approaches:
- Basically recursive technique to find combination sum,subset sum etc
- Technique to avoid repeatition of same set in result set by sorting + skipping prev same element

## Day 10
### Approaches
- Reaching home from given points where in rather then trying all paths from start
  since given end points, we can simply approach to those end points from start and find the cost.
- Coloring graph by ietrating via nodes and backtracking when current combo fails or succeeds.
- Trying queen combos on board and backtracking as and when necessary.
- Rat in maze uses power of backtracking and visisted matrix. Hoever edge cases considering 
  blocks at start and destination matters and skipping long soln procedure.
- Sudoku solver which tries each combo of chars to find appropriate fit,
  trick/formula to check 3*3 sub-matrix in 9*9 big matrix. ** if (board[3 * (r / 3) + (i / 3)][3 * (c / 3) + (i % 3)] == ch) ** 
  where ch is character currently we are trying to place.

