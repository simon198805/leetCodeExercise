#include "include.hpp"
/*
 * @lc app=leetcode id=1104 lang=cpp
 *
 * [1104] Path In Zigzag Labelled Binary Tree
 */

// @lc code=start
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        bool rev = true;
        int baseNum = exp2(int(log2(label)));
        int rawNum = label;
        res.push_back(label);
        int showNum;
        while(rawNum > 1)
        {
            baseNum/=2;
            rawNum = rawNum/2;
            showNum = rawNum;
            if(rev)
            {
              showNum = baseNum * 3 - rawNum - 1;  
            }
            res.push_back(showNum);
            rev = !rev;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

