//Codeforces Round 993 (Div. 4) E. Insane Problem
//https://codeforces.com/contest/2044/problem/E
#include <bits/stdc++.h>
#define int long long
using namespace std;

int ntests, k, l1, r1, l2, r2, res;

int power(int x, int y)
{
    if(y == 0)
        return 1ll;

    int z = power(x, y / 2);
    if(y % 2 == 0)
        return z * z;
    else
        return z * z * x;
}

void solve()
{
    cin >> k >> l1 >> r1 >> l2 >> r2;
    
    res = 0ll;
    for(int i = 0; i <= log10(1000000000) / log10(k); i++)
    {
        int a = power(k, i); 
        if(a * r1 < l2 || a * l1 > r2)
            continue;
        int b = a * l1;
        int c = a * r1;
        int d = max(b, l2);
        int e = min(c, r2);
        int f = d / a;
        if(d % a > 0)
            f++;
        int g = e / a;
        res += g - f + 1;
        //cout << res << ' ';
    }

    cout << res << '\n';
}   

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();
    
    return 0;
}