//Codeforces Round 983 (Div. 2): A. Circuit
//https://codeforces.com/contest/2032/problem/A

#include <bits/stdc++.h>
using namespace std;

const int N = 109;
int ntests, n, a[N], cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while (ntests--)
    {
        cnt = 0;
        cin >> n;
        for(int i = 1; i <= n * 2; i++)
        {
            cin >> a[i];
            if(a[i] == 1)
                cnt++;
        }
        cout << cnt % 2 << ' ';
        if(cnt <= n)
            cout << cnt << '\n';
        else
            cout << 2 * n - cnt << '\n';
    }
    
    return 0;
}