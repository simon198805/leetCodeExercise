# include "include.hpp"
/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int points  = 0;
        vector<pair<int,int>> work;
        work.push_back({0,0});
        for (size_t i = 0; i < profit.size(); i++)
        {
            work.push_back({profit[i], difficulty[i]});
            //cout << "w" << profit[i] << "," << difficulty[i] << endl;
        }
        sort(work.begin(),work.end());
        sort(worker.begin(),worker.end());
        int i = worker.size() -1 ;
        int workSize = work.size()-1;

        for (; i >=0 ; i--)
        {
            int j = workSize;
            const int wp = worker[i];
            while (wp < work[j].second && j > 0) j--;
            if (j == 0) break;
            points += work[j].first;
        }
        return points;

    }
};
// @lc code=end

