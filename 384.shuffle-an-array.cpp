#include "include.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>

/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

// @lc code=start
class Solution {
public:     
    vector<int> rawNums;
    vector<int> nums;
    int numSize;
    Solution(vector<int>& nums) {
        rawNums = nums;
        this->nums = nums;
        numSize = nums.size();
        cout << numSize;
        srand (time(NULL)); 
    }
    

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        //nums = rawNums;
        return rawNums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::random_shuffle ( nums.begin(), nums.end());
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

