/* 826. Most Profit Assigning Work
You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs.

Gratuitous use of the editorial available.  
But I understand the Left & Right pointer system better now, and how to initialize and fill vector pairs, which has come up before.
*/

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int profits = 0;
        
        vector<pair<int,int>> jobProfile{(0,0)};
        jobProfile.push_back({0, 0});
        for (int i = 0; i < difficulty.size(); i++)
        {
            jobProfile.push_back({difficulty[i],profit[i]});
        }

        sort(jobProfile.begin(),jobProfile.end());
        for (int i = 0; i < jobProfile.size()-1; i++)
        {
            jobProfile[i + 1].second = max(jobProfile[i].second, jobProfile[i + 1].second);
        }

        for (int i = 0; i < worker.size(); i++)
        {
            int ability = worker[i];

            int l = 0, r = jobProfile.size() - 1, jobProfit = 0;
            while (l <= r) {
                int mid = (l +r) / 2;
                if (jobProfile[mid].first <= ability)
                {
                    jobProfit = max(jobProfit, jobProfile[mid].second);
                    l = mid + 1;
                } else
                {
                    r = mid - 1;
                }
            }
        profits += jobProfit;
        }
    return profits;
    }
};
