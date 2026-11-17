class Solution:

    def generateParenthesis(self, n: int) -> list[str]:
        s = {"": 0}

        def myFunc(i):    
            temp = s.copy()

            for k in temp.keys():
        
                c = s.get(k)

                if s[k] >= 0 and s[k] < 2*n - i:
                    s[k + "("] = c + 1

                if s[k] > 0:
                    s[k + ")"] = c - 1

                s.pop(k)

            if i >= 2*n - 1:
                return

            myFunc(i+1)

        myFunc(0)
        return list(s.keys())


s = Solution().generateParenthesis(4)
print(s)