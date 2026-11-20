#include <iostream>
#include <vector>

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

        for (int i = 0; i < nums.size(); ++i)
        {
            vector<int> nextVec(vec);
            nextVec[0]++;
            nextVec[nextVec[0]] = nums[i];
            vector<int> nextNums(nums);
            nextNums.erase(nextNums.begin() + i);
            dp(nextVec, nextNums, res);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> base(nums.size() + 1, 0);
        dp(base, nums, res);
        return res;
    }
};

int main() {}
