from typing import List

class Solution:
    def minOperations(self, boxes: str) -> List[int]:

        left_count, left_cost = 0, 0
        right_count, right_cost = 0, 0
        n = len(boxes)
        ans = [0] * n

        for i in range(1, n):
            if boxes[i - 1] == "1":
                left_count += 1
            left_cost += left_count
            ans[i] += left_cost

            if boxes[n - i] == "1":
                right_count += 1
            right_cost += right_count
            ans[n - 1 - i] += right_cost

        return ans


print(Solution().minOperations("110"))
