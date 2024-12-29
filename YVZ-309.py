#Educational Codeforces Round 173 (Rated for Div. 2) A. Coin Transformation
#https://codeforces.com/contest/2043/problem/A

def solve():
    n = int(input())
    res = 1
    while n > 3:
        n //= 4
        res *= 2
    print(res)

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1