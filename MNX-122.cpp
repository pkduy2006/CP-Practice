//Codeforces Round 991 (Div. 3) E. Three Strings
//https://codeforces.com/contest/2050/problem/E
#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 8;
const int INF = 1e9 + 7;
int ntests, n, m, f[N][N];
string a, b, c;

void solve()
{
    cin >> a >> b >> c;
    n = a.size(), m = b.size();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            f[i][j] = INF;
    }

    a = ' ' + a;
    b = ' ' + b;
    c = ' ' + c;
    f[0][0] = 0;
    for(int i = 1; i <= n; i++)
        f[i][0] = f[i - 1][0] + (a[i] != c[i]);
    for(int j = 1; j <= m; j++)
        f[0][j] = f[0][j - 1] + (b[j] != c[j]);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            f[i][j] = min(f[i - 1][j] + (a[i] != c[i + j]), f[i][j - 1] + (b[j] != c[i + j]));
    }
    //cout << f[1][1] << '\n';
    cout << f[n][m] << '\n';
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