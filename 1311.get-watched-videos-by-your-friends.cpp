#include "include.hpp"
/*
 * @lc app=leetcode id=1311 lang=cpp
 *
 * [1311] Get Watched Videos by Your Friends
 */

// @lc code=start
class Solution {
    int mySelf;
    void FindFriends(vector<vector<int>>& friends, int &me, int &level, set<int> &myLevelNFriends)
    {

        vector<int> &myFriends = friends[me];
        int myFriendsCount = myFriends.size(); 
        if(level == 1)
        {
            for (auto &&i : myFriends)
            {
                if(i != mySelf)
                myLevelNFriends.insert(i);                
            }
            return;
        }

        int nextLv = level-1;
        for (auto &&i : myFriends)
        {
            if(i != me)
            FindFriends(friends,i,nextLv,myLevelNFriends);
        }
    }
    static bool CompareValueThenKey(pair<string,int> &p1, pair<string,int> &p2)
    {
        if(p1.second == p2.second)
        {
            //if(p1.second == 4)
            //cout << p1.first << "," << p2.first << p1.first.compare(p2.first)<<";";
            return p1.first.compare(p2.first) < 0;
        }
        return p1.second < p2.second;
    }

public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        mySelf = id;
        set<int> myLevelNFriends;
        FindFriends(friends, id,level, myLevelNFriends);
        map<string,int> levelNFriendsVideos;
        cout << "lvNFriends";
        for (auto &&thisFriend : myLevelNFriends)
        {
            cout << thisFriend << ",";
            for (auto &&video : watchedVideos[thisFriend])
            {
                levelNFriendsVideos[video]++;
            }            
        }
        cout << endl;
        vector<string> res;
        // sort
        vector<pair<string,int>> sortContainer;
        for(auto &&video : levelNFriendsVideos)
            sortContainer.push_back(make_pair(video.first,video.second));
        sort(sortContainer.begin(),sortContainer.end(),CompareValueThenKey);
        cout << endl;
        for (auto &&siPair : sortContainer)
        {
            cout<<siPair.first<<siPair.second<< ",";
            res.push_back(siPair.first);
        }
        return res;

    }
};
// @lc code=end

