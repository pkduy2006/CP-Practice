//Codeforces Round 993 (Div. 4) C. Hard Problem
//https://codeforces.com/contest/2044/problem/C
#include <bits/stdc++.h>
using namespace std;

int ntests, m, a, b, c;

void solve()
{
    cin >> m >> a >> b >> c;
    if(a < m && b < m)
        cout << a % m + b % m + min(c, 2 * m - a % m - b % m) << '\n';
    else if(a >= m && b < m)
        cout << m + b % m + min(c, m - b % m) << '\n';
    else if(a < m && b >= m)
        cout << a % m + m + min(c, m - a % m) << '\n';
    else
        cout << 2 * m << '\n';
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