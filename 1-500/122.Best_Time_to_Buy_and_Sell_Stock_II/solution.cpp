#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int start = 0, end = 0, sum = 0, size = prices.size(), temp_sum = 0;
        for (int i = 1; i < size; ++i)
        {
            if (prices[i - 1] < prices[i])
            {
                end = i;
                continue;
            }
            if (start < end)
                sum += prices[end] - prices[start];
            start = i;
        }

        temp_sum = prices[size - 1] - prices[start];
        if (temp_sum > 0)
            sum += temp_sum;

        return sum;
    }
};

int main()
{
    vector<int> v = {7, 8, 6, 4, 3, 1};
    cout << Solution().maxProfit(v) << endl;
}