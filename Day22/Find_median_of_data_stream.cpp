/*

295. Find Median from Data Stream
Hard
9.8K
188
Companies
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
 

Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
*/

#include <bits/stdc++.h>
using namespace std;


class MedianFinder {
public:
    //As per neetcode
    //We will have two heaps
    // smaller heap wioll be max_heap
    // larger heap will be min heap
    priority_queue<int> smaller;
    priority_queue<int,vector<int>,greater<int>> larger;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(smaller.empty()){
            smaller.push(num);
                 
            return;
        }
         smaller.push(num);
       
        //If sizes becomes uequal
        // => size differnce can be at max 1
        //    but not greater
        // => sine adding elemnts in smalle rwe check against smaller size  
        if(smaller.size()-larger.size()>=2){
               // pop  maximum element from smaller and push into larger
               int max_ele=smaller.top();
               smaller.pop();
               larger.push(max_ele);
            
        }
        
        // Incase the element added in smaller heap is greater the larger heap
        // element we know that all_ele_of_smaller_heap<=all_ele_of_larger_heap
        if(smaller.top()>larger.top()){
            int max_ele=smaller.top();
            smaller.pop();
            larger.push(max_ele);
          
        }
  
   

       //Again ther can be size differnce hence this time we addelement to larger heap
        if(smaller.size()-larger.size()>1){
               // pop  maximum element from smaller and push into larger
               int min_ele=larger.top();
               larger.pop();
               smaller.push(min_ele);
                 
              
        }
   
    }
    
    double findMedian() { 
        int size=smaller.size()+larger.size();
        if(size%2!=0){
            if(smaller.size()>larger.size()){
                return (double)smaller.top();
            }
            return larger.top();
        }
        else{
            return (double)(smaller.top()+larger.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */