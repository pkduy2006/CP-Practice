//Codeforces Round 995 (Div. 3) B. Journey
//https://codeforces.com/contest/2051/problem/B

#include <bits/stdc++.h>
using namespace std;

int ntests, n, a, b, c;

void solve()
{
    cin >> n >> a >> b >> c;

    int res = n / (a + b + c) * 3;
    if(n % (a + b + c) == 0)
        cout << res << '\n';
    else
    {
        int d = n % (a + b + c);
        res++;
        d -= a;
        if(d > 0)
        {
            res++;
            d -= b;
            if(d > 0)
                res++;
        }
        cout << res << '\n';
    }
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