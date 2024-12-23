//Codeforces Round 995 (Div. 3) D. Counting Pairs
//https://codeforces.com/contest/2051/problem/D

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int ntests, n, a[N];
long long sum, res, x, y;

void solve()
{
    sum = 0;
    res = 0;

    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++)
    {
        long long l = sum - y - a[i], r = sum - x - a[i];

        int lid = lower_bound(a + 1, a + 1 + n, l) - a;
        int rid = upper_bound(a + 1, a + 1 + n, r) - a - 1;
        res += rid - lid + 1;
        if(lid <= i && i <= rid)
            res--;
    }

    cout << res / 2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();

    return 0;
}