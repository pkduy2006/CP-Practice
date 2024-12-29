#Educational Codeforces Round 173 (Rated for Div. 2) B. Digits
#https://codeforces.com/contest/2043/problem/B

def solve():
    n, d = map(int, input().split())
    print(1, end=' ')
    if d % 3 == 0 or n >= 3:
        print(3, end=' ')
    if d == 5:
        print(5, end=' ')
    if d == 7 or n >= 3: 
        print(7, end=' ')
    if d == 9 or n >= 6 or (d % 3 == 0 and n >= 3):
        print(9, end=' ')
    print()

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1