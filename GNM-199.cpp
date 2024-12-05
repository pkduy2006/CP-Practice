//Educational Codeforces Round 172 (Rated for Div. 2) B. Game with Colored Marbles
//https://codeforces.com/contest/2042/problem/B
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 8;
int ntests, n, a[N], cnt[N];

void solve()
{
    fill(cnt + 1, cnt + 1 + n, 0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {   
        cin >> a[i];
        cnt[a[i]]++;
    }

    int c = 0, res = 0, d = 0;
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] == 1)
            c++;
        else if(cnt[i] != 0)
            d++;
    }
   // cout << c << ' ' << d << '\n';
    res += (c / 2) * 2;
    if(c % 2 == 1)
        res += 2;
    res += d;
    cout << res << '\n';
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