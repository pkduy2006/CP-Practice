//Bedao Mini Contest 25 - Ước chia hết
//https://oj.vnoi.info/problem/bedao_m25_b
#include <bits/stdc++.h>
#define int long long
using namespace std;

int a, b, c, n;

int count_gcd(int x, int y)
{
    while(y != 0)
    {
        int t = y;
        y = x % y;
        x = t;
    }

    return x;
}

int count_lcm(int x, int y)
{
    int tmp = count_gcd(x, y);
    if(y / tmp > n / x)
        return -1;
    return x * (y / tmp);
}

int solve(int x, int y)
{
    if(n % x != 0 || n % y != 0)
        return 0ll;
    
    int xy = count_lcm(x, y);
    if(xy == -1)
        return 0ll;
    int m = n / xy, res = 0ll;
    for(int i = 1; i * i <= m; i++)
    {
        if(m % i == 0)
        {
            if(i * i == m)
                res++;
            else
                res += 2;
        }
    }
    return res;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> c;
    cout << solve(a, b) + solve(b, c) + solve(c, a) - 2 * solve(count_lcm(a, b), c);
    //cout << count_gcd(a, b);
    return 0;
}
