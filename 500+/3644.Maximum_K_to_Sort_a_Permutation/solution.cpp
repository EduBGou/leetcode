#include <vector>

using namespace std;

class Solution
{
public:
    int sortPermutation(vector<int> &nums)
    {
        int k = 0;
        int c = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == nums[i]) continue;
            c++;
            if (c == 1)
            {
                k = nums[i];
                continue;
            }
            k &= nums[i];
            if (k == 0)
                return 0;
        }
        return k;
    }
};

int main()
{
    vector<int> ipt = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 12, 11, 14, 13};
    auto s = Solution().sortPermutation(ipt);
}