//Codeforces Round 991 (Div. 3) B. Transfusion
//https://codeforces.com/contest/2050/problem/B
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 7;
int ntests, n, a[N];

void solve()
{
    int sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    
    for(int i = 2; i <= n - 1; i++)
    {
        if(a[i - 1] > sum / n)
            a[i + 1] += a[i - 1] - sum / n;
        else
            a[i + 1] -= sum / n - a[i - 1];
        a[i - 1] = sum / n;
    }

    bool check = true;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] != sum / n)
        {
            check = false;
            break;
        }
    }
    //for(int i = 1; i <= n; i++)
       // cout << a[i] << ' ';
    //cout << '\n';
    if(check && sum % n == 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();
    
    return 0;
}