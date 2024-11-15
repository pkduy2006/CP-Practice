//Codeforces Round 987 (Div. 2) C. Penchick and BBQ Buns
//https://codeforces.com/contest/2031/problem/C
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 8;
int ntests, n, a[N];

void solve()
{
    cin >> n;
    if(n % 2 == 0)
    {
        for(int i = 1; i <= n; i += 2)
            cout << i << ' ' << i << ' ';
        cout << '\n';
    }
    else
    {
        if(n < 27)
            cout << -1 << '\n';
        else
        {
            fill(a + 1, a + 1 + n, 0);
            a[1] = 1;
            a[10] = 1;
            a[26] = 1;
            a[23] = 2;
            a[27] = 2;
            int value = 3, cnt = 0;
            for(int i = 1; i <= n; i++)
            {
                if(a[i] != 0)
                    continue;
                a[i] = value;
                cnt++;
                if(cnt == 2)
                {
                    cnt = 0;
                    value++;
                }
            }
            for(int i = 1; i <= n; i++)
                cout << a[i] << ' ';
            cout << '\n';
        }
    }
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