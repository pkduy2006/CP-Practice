//Codeforces Round 995 (Div. 3) A. Preparing for the Olympiad
//https://codeforces.com/contest/2051/problem/A

#include <bits/stdc++.h>
using namespace std;

const int N = 107;
int ntests, n, a[N], b[N];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    
    int res = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i] >= b[i + 1])
            res += a[i] - b[i + 1];
    }
    res += a[n];

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