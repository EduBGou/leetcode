from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
     left, right = 0, len(numbers)-1
     while True:
        s = numbers[left] + numbers[right]
        if s < target:
           left += 1
        elif s > target:
           right -= 1
        else:
           return [1+left, 1+right]
        
        
print(Solution().twoSum([5, 25, 75], 100))