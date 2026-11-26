class Solution:
    def canAliceWin(self, n: int) -> bool:
        isAlice = True
        for i in range(10, 0, -1):
            n -= i
            isAlice = not isAlice
            if n < 0:
                return isAlice
        return True   