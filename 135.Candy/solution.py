import time
from typing import List

class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        y = [1] * n
        rs_ratings = sorted(list(set(ratings)))
        sum = ratings.count(rs_ratings[0])

        for i in range(1, len(rs_ratings)):
            j = 0
            while True:
                try:
                    j = ratings.index(rs_ratings[i], j)
                except:
                    break
                
                if j > 0 and ratings[j-1] < ratings[j]:
                    y[j] = y[j-1] + 1

                if j < n-1 and ratings[j+1] < ratings[j]:
                    y[j] = max(y[j+1] + 1, y[j])
                
                sum += y[j]
                j += 1

        return sum


s = Solution()
begin = time.perf_counter()
# print(s.candy([1,0,2]))

end = time.perf_counter()
total_time = end - begin
print(f"Time: {total_time:.4f} sec")