from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height)-1
        greatest = 0

        while left < right:                
            current_height = min(height[left], height[right])        
            greatest = max(current_height * (right - left), greatest)
            if current_height == height[left]:
                left += 1
            else:
                right -= 1
        return greatest
