#include <vector>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int longestInc = 1, longestDec = 1;
        int tempInc = 1, tempDec = 1;

        for (int i = 1; i < nums.size(); i++){
            if (nums[i - 1] < nums[i]){
                tempInc++;
                if (tempInc > longestInc){
                    longestInc = tempInc;
                }
            }else{
                tempInc = 1;
            }

            if (nums[i] < nums[i - 1]){
                tempDec++;
                if (tempDec > longestDec){
                    longestDec = tempDec;
                }

            }else{
                tempDec = 1;
            }
        }
        return max(longestInc, longestDec);
    }
};

int main(){}