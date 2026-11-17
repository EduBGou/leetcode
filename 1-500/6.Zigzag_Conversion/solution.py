class Solution:
    def convert(self, s: str, numRows: int) -> str:
        import math
        n = len(s)
        p = 2 * numRows - 2 if numRows > 1 else 1
        k = math.ceil((n / p)) + 1
        rows = [""] * numRows

        for i in range(k):
            pos = p * i
            for j in range(numRows):
                if pos - j >= n:
                    j += pos - n + 1
                    continue

                if pos - j > 0 and j != 0 and j != numRows - 1:
                    rows[j] += s[pos - j]
                if pos + j < n:
                    rows[j] += s[pos + j]

        return "".join(rows)


print(Solution().convert("PAYPALISHIRING", 5))
