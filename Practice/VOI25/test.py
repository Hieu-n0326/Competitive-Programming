n = int (input())
a = []
xet = 1
while xet <= n:
    xet = xet * 3
xet = xet // 3
while n >= 0:
    if (n >= xet):
        a.append(xet)
        n = n - xet