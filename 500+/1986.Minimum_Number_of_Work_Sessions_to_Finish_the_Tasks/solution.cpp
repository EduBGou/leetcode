#include <vector>

using namespace std;

class Solution
{
public:
    int minSessions(vector<int> &tasks, int sessionTime)
    {
        int sessions = 0;
        int left = 0;
        int right = tasks.size() - 1;
        int ac = 0;
        int lastState = 0;

        while (tasks.size() > 0)
        {
            int sum = tasks[left] + tasks[right] + ac;

            if (sum == sessionTime)
            {
                tasks.erase(tasks.begin() + left);
                tasks.erase(tasks.begin() + right - 1);
                left = 0;
                right = tasks.size() - 1;
                sessions++;
                lastState = 0;
            }

            if (sum < sessionTime)
            {
                if (left == right - 1)
                {
                    ac = tasks[left];
                    left = 0;
                }
                left++;
                lastState = -1;
                
            }
            else
            {
                if (lastState == -1)
                {
                    tasks.erase(tasks.begin() + left - 1);
                    tasks.erase(tasks.begin() + right - 1);
                    lastState = 0;
                    sessions++;
                    right = tasks.size() - 1;
                    left = 0;
                }
                else
                {
                    right--;
                    
                }
            }
        }

        return sessions;
    }
};