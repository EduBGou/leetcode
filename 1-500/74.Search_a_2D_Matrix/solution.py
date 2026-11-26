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


tests = [
    ([[1, 3, 5], [7, 9, 11]], 5, True),
    ([[1, 3, 5], [7, 9, 11]], 7, True),
    ([[1, 3, 5], [7, 9, 11]], 11, True),
    ([[1, 3, 5], [7, 9, 11]], 6, False),
    ([[1, 3, 5], [7, 9, 11]], 0, False),
    ([[1, 3, 5], [7, 9, 11]], 12, False),
    ([[1]], 0, False),
    ([[1]], 1, True),
    ([[1]], 2, False),
    ([[1, 2, 3, 4]], 4, True),
    ([[1, 2, 3, 4]], 5, False),
    ([[1], [2], [3], [4]], 3, True),
    ([[1], [2], [3], [4]], 5, False),
    ([[1, 3, 5, 7], [9, 11, 13, 15], [17, 19, 21, 23], [25, 27, 29, 31]], 19, True),
    ([[1, 3, 5, 7], [9, 11, 13, 15], [17, 19, 21, 23], [25, 27, 29, 31]], 20, False),
    ([[1, 3, 5, 7], [9, 11, 13, 15], [17, 19, 21, 23], [25, 27, 29, 31]], 1, True),
    ([[1, 3, 5, 7], [9, 11, 13, 15], [17, 19, 21, 23], [25, 27, 29, 31]], 31, True),
    ([[]], 1, False),
]

solution = Solution()

for i, (matrix, target, expected) in enumerate(tests, 1):
    try:
        result = solution.searchMatrix(matrix, target)
        status = "PASS" if result == expected else "FAIL"
        print(f"Test {i}: {status} | Expected: {expected}, Got: {result}")
    except Exception as e:
        print(f"Test {i}: ERROR | {type(e).__name__}: {e}")
