# include "include.hpp"
/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
class Solution {
    struct Worker
    {
        /* data */
        int id,power;
    };
    struct Work
    {
        int difficulty, profit;
        Work(int difficulty, int profit)
        {
            this->difficulty = difficulty;
            this->profit = profit;
        }
    };
    static bool compareWork(Work &i,Work &j)
    {
        return i.profit < j.profit;
    }
    bool compareWorkDif(Work &i,Work &j)
    {
        return i.difficulty < j.difficulty;
    }    
    
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int minStartWork = 0;
        int points  = 0;
        vector<Work> work;
        work.push_back(Work(0,0));
        for (size_t i = 0; i < profit.size(); i++)
        {
            work.push_back(Work(difficulty[i],profit[i]));
        }
        sort(work.begin(),work.end(),compareWork);
        sort(worker.begin(),worker.end());
        for (size_t i = 0; i < worker.size(); i++)
        {
            // at least pick the hardest one
            for (size_t j = work.size()-1; j > minStartWork; j--)
            {
                /* code */
                if (worker[i] < work[j].difficulty)
                {
                    // can't do, keep try
                }
                else
                {
                    // can do
                    minStartWork = j;
                    break;
                }  
            }
            //
            points += work[minStartWork].profit;
        }
        return points;

    }
};
// @lc code=end

