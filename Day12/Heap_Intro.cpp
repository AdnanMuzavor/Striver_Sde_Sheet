
#include <bits/stdc++.h>
using namespace std;

/*
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
- **MAX HEAP** : priority_queue<int> max_heap;
- **MIN HEAP** : priority_queue<int,vector<int>,greater<int>> min_heap
- **If Multiple values** :
    - It's better to use typedef and define your values
    - example heap having pair<int,pair<int,int>>
    - typedef pair<int,pair<int,int>>  ppi
    - priority_queue<ppi,vector<ppi>,greater<ppi>> min_heap

*/