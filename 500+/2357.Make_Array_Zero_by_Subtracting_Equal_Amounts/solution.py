from typing import List

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        nums.sort()
        greatest = nums[len(nums) - 1]
        c = 0
        op = 0
        for i in nums:
            if greatest == c:
                break
            if i == c:
                continue
            
            c = i
            op += 1

        return op


print(Solution().minimumOperations([1,5,0,3,5]))