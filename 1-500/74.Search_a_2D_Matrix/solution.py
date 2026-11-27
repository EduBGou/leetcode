class Solution:
    def dp(self, matrix, target, start, end):

        m = len(matrix[0])
        p = (start + end) // 2

        iPos = p // m
        jPos = p % m
        get = matrix[iPos][jPos]

        if get == target:
            return True
        elif target < get:
            if iPos + jPos == 0:
                return False    
            return self.dp(matrix, target, start, p)
        else:
            if start == p:
                iPos = end // m
                jPos = end % m
                return matrix[iPos][jPos] == target
            return self.dp(matrix, target, p, end)

    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        size = len(matrix) * len(matrix[0])
        if size == 0:
            return False
        return self.dp(matrix, target, 0, size - 1)

