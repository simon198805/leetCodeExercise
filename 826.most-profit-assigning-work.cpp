# include "include.hpp"
/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
class Solution {
    struct Work
    {
        int difficulty, profit;
        Work(int &difficulty, int &profit)
        {
            this->difficulty = difficulty;
            this->profit = profit;
        }
    };
    static inline bool compareWork(const Work &i,const Work &j)
    {
        return i.profit < j.profit;
    }
    
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int minStartWork = 0;
        int points  = 0;
        vector<Work> work;
        int zero = 0;
        work.push_back(Work(zero,zero));
        for (size_t i = 0; i < profit.size(); i++)
        {
            work.push_back(Work(difficulty[i],profit[i]));
        }
        sort(work.begin(),work.end(),compareWork);
        sort(worker.begin(),worker.end());
        const int workerSize = worker.size();
        const int workSize = work.size();

        for (size_t i = 0; i < workerSize; i++)
        {
            // at least pick the hardest one
            for (size_t j = workSize-1; j > minStartWork; j--)
            {
                /* code */
                if (worker[i] >= work[j].difficulty)
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

