

def comb(list: list[int], n: int) -> list[list[int]]:
    res = []
    if n == 0:
        return list
    
    for i in range(len(list) - n):
        res.append(comb(list[i+1:], n-1))

    return res

print(comb([1,2,3], 2))