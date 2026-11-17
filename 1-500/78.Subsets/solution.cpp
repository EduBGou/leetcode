#include <unordered_set>
#include <iostream>
#include <vector>
#include <bit>

using namespace std;

class Solution
{
public:
    void dp(unsigned int set, unordered_set<unsigned int> &memo)
    {
        for (int i = 0; i < bit_width(set); ++i)
        {
            if ((set & (1 << i)) == 0)
                continue;

            auto nextSet = set ^ (1 << i);
            memo.insert(nextSet);
            dp(nextSet, memo);
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        unordered_set<unsigned int> setRes;
        int mask = (1 << nums.size()) - 1;
        dp(mask, setRes);

        setRes.insert(mask);

        vector<unsigned int> vecRes(setRes.begin(), setRes.end());
        vector<vector<int>> res;

        for (unsigned int i = 0; i < vecRes.size(); ++i)
        {
            res.push_back(vector<int>());
            auto v = vecRes[i];
            for (unsigned int b = 0; b < nums.size(); ++b)
            {  
                if ((v & (1 << b)) == 0)
                    res[i].push_back(nums[b]);
            }
        }
        return res;
    }
};

int main(){}