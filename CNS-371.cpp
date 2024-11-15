//https://codeforces.com/contest/2031/problem/B
//Codeforces Round 987 (Div. 2) B. Penchick and Satay Sticks
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;
int ntests, n, p[N];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];

    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        if(abs(p[i] - i) >= 2)
            res++;
    }

    if(res == 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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