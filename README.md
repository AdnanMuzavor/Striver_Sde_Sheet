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

## Day 11
### Algorithm/technique: Binary Search
- To find first position we binary serahc in left most side and vice versa at every iteration.
- To find kth elements we basically use two pointer approach and counter to stop when we reach kth element
- Median of two arrays is found by using same above approach yet can be optimised.
- Search in rotated sorted array rolls round concept of Binary Search however its very important to check/compare
  element at low and high with mid so that we can decide where our target element will fit accordingly we move pointers.
  However in PART II we learn to decrease number of iterations simply by comparing element at low and high with mid and if same
  we decrease them equally to reduce window size
- Single elemnt in sorted array can be found by **XORING** But binary search approach can be used which has to be traced and 
  learnt for understanding. 

## Day 12
## Data Structure: Heap
## Reference: Aditya Verma Sir!
### Identification: 
- Look for **k**
- You're asked **smallest/largest**
### Which heap when?
- When asked for eg kth min use max heap.
- When asked for eg kth max use min heap.
### Why heap?
- In above questions, otherwise we would have sorted array using NlogN complexity
- When we use heap say of size k we reduce complexity from NlogN to NlogK
### Implementation?
- It's preferable to use STLs a
- **MAX HEAP** : priority_queue<<int>> max_heap;
- **MIN HEAP** : priority_queue<int,vector<<int>>,greater<<int>>> min_heap
- **If Multiple values** :
    - It's better to use typedef and define your values
    - example heap having pair<int,pair<int,int>>
    - typedef pair<int,pair<int,int>>  ppi
    - priority_queue<ppi,vector<<ppi>>,greater<<ppi>>> min_heap


## Day 17
### Approach name: Vertical Traversal
- Vertical traversal is tarversal of binary tree interms of vertical lines from left to right.
- ***Applications***: Top and Bottom view of a binary tree.
### Approach name: Level Traversal
- Level order traversal of binary tree is it's traversal from top to bottom.
- ***Applications***: 
- left and right view of a binary tree.
- level order + indexing to find maximum width.
- Indexing is further expanded to avoid OVERFLOW issue which might occur in left/right only
  Binary trees, in this appraoch w emake sure that each level indexes start from 1 till n
  this is acjieved by subtracting from minimum.
- Using recursion to find path to given node, approach used is: **Preorder**




