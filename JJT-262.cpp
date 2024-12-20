//Codeforces Round 994 (Div. 2) C. MEX Cycle
//https://codeforces.com/contest/2049/problem/C
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int ntests, n, x, y, res[N];

void solve()
{
    cin >> n >> x >> y;
    if(n % 2 == 0 && (y - x) % 2 == 1)
    {
        for(int i = 1; i <= n; i += 2)
        {
            res[i] = 1;
            res[i + 1] = 0;
        }
        //cout << 1 << '\n';
    }
    else
    {
        res[x] = 2;
        for(int i = x + 1; i <= n; i += 2)
        {
            res[i] = 1;
            res[i + 1] = 0;
        }
        if(res[n] == 0)
        {
            for(int i = 1; i <= x - 1; i += 2)
            {
                res[i] = 1;
                if(i + 1 != x)
                    res[i + 1] = 0;
            }
        }
        else
        {
            for(int i = 1; i <= x - 1; i += 2)
            {
                res[i] = 0;
                if(i + 1 != x)
                    res[i + 1] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << '\n';
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