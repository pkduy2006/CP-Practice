//Codeforces Round 988 (Div. 3) A. Twice
//https://codeforces.com/contest/2037/problem/A
#include <bits/stdc++.h>
using namespace std;

const int N = 28;
int ntests, n, mark[N], res;

void solve()
{
    fill(mark, mark + N, 0);
    res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mark[x]++;
    }

    for(int i = 1; i <= n; i++)
        res += mark[i] / 2;

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while (ntests--)
        solve();
    
    return 0;
}