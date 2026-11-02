class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums_sorted = sorted(list(nums))
        res = []
        n = len(nums_sorted)

        for i in range(n-2):
            left = i+1
            right = n-1
            if i > 0 and nums_sorted[i] == nums_sorted[i-1]:
                continue
            while left < right:
                ni = nums_sorted[i]
                nl = nums_sorted[left]
                nr = nums_sorted[right]

                s = ni + nl + nr

                if s < 0:
                    left += 1
                elif s > 0:
                    right -= 1
                else:
                    left += 1
                    while left < right and nums_sorted[left-1] == nums_sorted[left]:
                        left += 1

                    res.append([ni, nl, nr])
        return res



print(Solution().threeSum([0,0,0,0]))
print(Solution().threeSum())
