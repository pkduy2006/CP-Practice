#Codeforces Round 460 (Div. 2) B. Perfect Number
#https://codeforces.com/contest/919/problem/B
def cal(x):
    ans = 0
    while x > 0:
        ans += x % 10
        x /= 10
        x = int(x)
    return ans

k = int(input())
cnt = 0
res = 1
while cnt < k:
    res += 1
    if cal(res) == 10:
        cnt += 1
print(res)