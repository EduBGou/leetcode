from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        f = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }

        letters = []
        c = 1
        for x in range(len(digits)):
            l = f[digits[x]]
            letters.append(l)
            c *= len(l)

        comb = [""]*c
        step = 1
        for x in letters:
            r = int(c/len(x))
            for j in range(c):
                comb[j] += x[((j*step)//r)%len(x)]
            step *= len(x)
        return comb

print(Solution().letterCombinations("456"))
