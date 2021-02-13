#include "include.hpp"
/*
 * @lc app=leetcode id=1311 lang=cpp
 *
 * [1311] Get Watched Videos by Your Friends
 */

// @lc code=start
class Solution {
    int mySelf;
    vector<int> FindFriends(vector<vector<int>>& friends, int &me, int &level)
    {
        set<int> visitedFriends = {me};
        vector<int> friendsInThisLv = {me};
        for (size_t i = 0; i < level; i++)
        {            
            vector<int> friendsInNextLv;        
            for(auto &&thisLvFriend: friendsInThisLv)
            {
                for (auto &&nextLvFriend : friends[thisLvFriend])
                {
                    auto r = visitedFriends.insert(nextLvFriend);
                    if(r.second)
                    {
                        friendsInNextLv.push_back(nextLvFriend);
                    }
                }
            }
            friendsInThisLv = friendsInNextLv;
        }
        return friendsInThisLv;

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
        auto  myLevelNFriends = FindFriends(friends, id,level);
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

