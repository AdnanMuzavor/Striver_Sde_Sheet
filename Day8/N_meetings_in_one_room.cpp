/*
N meetings in one room
EasyAccuracy: 43.1%Submissions: 100k+Points: 2
Lamp
Crack Top Product Based Company Interviews with DSA Courses, Now at EXTRA 25% OFF!
Click Here to Claim!  

There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
Example 2:

Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}
Output: 
1
Explanation:
Only one meetings can be held
with given start and end timings.

Your Task :
You don't need to read inputs or print anything. Complete the function maxMeetings() that takes two arrays start[] and end[] along with their size N as input parameters and returns the maximum number of meetings that can be held in the meeting room.


Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)


Constraints:
1 ≤ N ≤ 105
0 ≤ start[i] < end[i] ≤ 105
*/

#include <bits/stdc++.h>
using namespace std;
//0(NlogN)+O(N)
class Solution
{
    struct meeting{
        int start;
        int end;
        int pos;
    };
    static bool comparator(struct meeting m1,struct meeting m2){
        if(m1.end<m2.end) return true;
        else if(m1.end>m2.end) return false;
        else if(m1.pos<m2.pos) return true;
        return false;
    }
    public:
    /*
      Given meetinggs:
      start : 1 0 3 8 5 8 
      end   : 2 6 4 7 7 9
      number: 1 2 3 4 5 6
      
      // -> Now can we scedule the maximum meetings?
      // -> obviously by choosing meeting whcih end faster
      // -> Hence we would definitely be able to accumulate more meetings
      
      after sorting :
      {1,2,1} =>  selected first so will execute first so selected (1)
      {3,4,3} => start time=3 which is greater then prev_end_time=2 so selected (2)
      {0,6,2} => start time=0 which is not greater then prev_end_time=4 so not selected
      {5,7,5} => start time=5 which is greater then prev_end_time=4 so selected (3)
      {8,9,4} => start time=8 which is greater then prev_end_time=7 so selected (4)
      {8,9,6} => start time=8 which is not greater then prev_end_time=9 so not selected
      
      //Hence o/p=4 order => 1,3,5,4
    */
    int maxMeetings(int start[], int end[], int n)
    {
        struct meeting meet[n];
        for(int i=0;i<n;i++){
            meet[i].start=start[i];
            meet[i].end=end[i];
            meet[i].pos=i;
        }
        
        //Sort meeting as per meeting which end first
        sort(meet,meet+n,comparator);
        int ans=1;
        //leep end time of first meeting
        int ended_at=meet[0].end;
        
        //As meetings are sorted based on end timel, check if current ith meeting can be started
        //and that is possible only if start>prev_end
        for(int i=1;i<n;i++){
            if(meet[i].start>ended_at){
                ans++;
                ended_at=meet[i].end;
            }
        }
        return ans;
    }
};