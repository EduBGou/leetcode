#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int x = nums[0];
        int countX = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == x) countX++;
            else countX--;

            if (countX == 0)
            {
                x = nums[i];
                countX++;
            }
        }
        return x;
    }
};
