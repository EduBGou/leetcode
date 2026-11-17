#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return {{}};
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> out = {};
    }
};