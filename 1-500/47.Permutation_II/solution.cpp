#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void dp(vector<int> vec, vector<int> &nums, vector<vector<int>> &res)
    {
        if (vec[0] == vec.size() - 1)
        {
            res.push_back(vector<int>(vec.begin() + 1, vec.end()));
            return;
        }
        unordered_set<int> tempSet;

        for (int i = 0; i < nums.size(); ++i)
        {
            if(tempSet.contains(nums[i])) continue;
            vector<int> nextVec(vec);
            nextVec[0]++;
            nextVec[nextVec[0]] = nums[i];
            vector<int> nextNums(nums);
            nextNums.erase(nextNums.begin() + i); 
            dp(nextVec, nextNums, res);
            tempSet.insert(nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> base(nums.size() + 1, 0);
        dp(base, nums, res);
        return res;
    }
};