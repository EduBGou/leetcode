#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        int count = 1, k = 0;

        for (int i=1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i-1]){
                count = 1;
                continue;
            }

            count++;
            if (count > 2)
            {
                nums.erase(nums.begin() + i);
                k += 1;
                i -= 1;
            }
        }

        return nums.size();
    }
};

int main() {}