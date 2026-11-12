#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> numbers(nums.begin(), nums.end());

        int maxCount = 0;

        for (int num : numbers)
        {
            if (numbers.find(num - 1) != numbers.end())
                continue;

            int current = num;
            int count = 1;

            while (numbers.find(current + 1) != numbers.end())
            {
                current++;
                count++;
            }

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};

int main(){}