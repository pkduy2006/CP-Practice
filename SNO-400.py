#Codeforces Round 984 (Div. 3) A. Quintomania
#https://codeforces.com/contest/2036/problem/A
def solve():
    n = int(input())
    a = list(map(int, input().split()))
    check = True
    for i in range(0, len(a) - 1):
        if abs(a[i] - a[i + 1]) != 5 and abs(a[i] - a[i + 1]) != 7:
            check = False
    if check == True:
        print("YES")
    else:
        print("NO")

ntests = int(input())
while ntests > 0:
    solve()
    ntests -= 1