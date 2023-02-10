/*
Job Sequencing Problem
MediumAccuracy: 48.94%Submissions: 100k+Points: 4
Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)


Constraints:
1 <= N <= 105
1 <= Deadline <= 100
1 <= Profit <= 500
*/

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
    // Sort the jobs in decreasing order of profit,
    // as aim here is to maximise the profits
    static bool comp(Job a, Job b)
    {
        if (a.profit > b.profit)
            return true;
        return false;
    }

    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {

        // Sort the jobs in order of increasing profits
        sort(arr, arr + n, comp);

        // -> If you carefully think..how should we schedule the process
        // -> say we have process with deadline 6
        // -> we can schedule it any time between 1 to 6
        // -> But if we choose the last possible deadline say 6
        // -> thn all thoe processes further which has deadline in range of 1 to 5
        // -> can be scheduled thus increasing the profits
        // -> while in othe rhand if w ehad chosen any value among 1 to 6
        // -> Thn we might not have been able to schedule an extra process who
        // -> has the deadline we have selected, although current process
        // -> could have been done later

        // find the maximum dealine possible
        int max_dd = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].dead > max_dd)
                max_dd = arr[i].dead;
        }

        // -> Now make array of this size
        // -> so that we can know if any process had been scheduled
        // -> to maximum possible dealdine,we can iterate and find next
        // -> maximum possible value to schedule it
        vector<int> scheduled(max_dd + 1, -1);

        // initialse the counter and profit to zero
        int counter = 0, profit = 0;

        // start scheduling the processes
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                // if at this maximum deadline for job i
                // nothing was scheduled, thn schedule it
                if (scheduled[j] == -1)
                {
                    scheduled[j] = arr[i].id;
                    counter++;
                    profit += arr[i].profit;
                    break; // -> break as this process is scheduled
                           // -> hence no need to look for next maximum possible
                           // -> deadline for the proces
                }
            }
        }

        // prepare soln vector
        vector<int> op(2, 0);
        op[0] = counter;
        op[1] = profit;
        return op;
    }
};