from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        sorted_nums = sorted(nums)
        n = len(sorted_nums)
        closest = sorted_nums[0] + sorted_nums[1] + sorted_nums[n - 1]

        for i in range(n - 2):
            left, right = i + 1, n - 1
            while left < right:
                s = sorted_nums[i] + sorted_nums[left] + sorted_nums[right]
                if s == target:
                    return s

                if s < target:
                    left += 1
                else:
                    right -= 1

                if abs(s - target) <= abs(closest - target):
                    closest = s


        return closest


print(
    Solution().threeSumClosest(
        [-84, 92, 26, 19, -7, 9, 42, -51, 8, 30, -100, -13, -38], 78
    )
)
