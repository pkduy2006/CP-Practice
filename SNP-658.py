# lqdoj: CSES Tower of Hanoi
# https://lqdoj.edu.vn/problem/cses2165
result = []

def solve(k, x, y, z):
    if k == 1:
        result.append((x, y))
    else:
        solve(k - 1, x, z, y)
        solve(1, x, y, z)
        solve(k - 1, z, y, x)

k = int(input())
solve(k, 1, 3, 2)
print(len(result))
for a, b in result:
    print(a, b)