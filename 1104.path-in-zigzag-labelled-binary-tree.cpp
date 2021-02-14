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
        res.push_back(label);
        while(label > 1)
        {
            baseNum/=2;
            label = label/2;
            res.push_back(rev?(baseNum * 3 - label - 1) :label);
            rev = !rev;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

