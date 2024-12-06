//Codeforces Round 991 (Div. 3) F. Maximum modulo equality
//https://codeforces.com/contest/2050/problem/F
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;
const int INF = 1e9 + 7;
int ntests, n, q, a[N], st[4 * N], b[N];

int count_gcd(int x, int y)
{
    while(y != 0)
    {
        int t = y;
        y = x % y;
        x = t;
    }

    return x;
}

void Build(int id, int l, int r)
{
    if(l == r)
    {
        st[id] = b[l];
        return;
    }

    int mid = (l + r) / 2;
    Build(id * 2, l, mid);
    Build(id * 2 + 1, mid + 1, r);
    st[id] = count_gcd(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int x, int y)
{
    if(r < x || y < l)
        return -1;
    if(x <= l && r <= y)
        return st[id];
    
    int mid = (l + r) / 2;
    if(get(id * 2, l, mid, x, y) == -1)
        return get(id * 2 + 1, mid + 1, r, x, y);
    if(get(id * 2 + 1, mid + 1, r, x, y) == -1)
        return get(id * 2, l, mid, x, y);
    return count_gcd(get(id * 2, l, mid, x, y), get(id * 2 + 1, mid + 1, r, x, y));
}

void solve()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++)
        b[i] = abs(a[i + 1] - a[i]);
    if(n > 1)
        Build(1, 1, n - 1);
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        if(l == r)
            cout << 0 << ' ';
        else
            cout << get(1, 1, n - 1, l, r - 1) << ' ';
    }
    cout << '\n';
    //for(int i = 1; i <= 20; i++)
      //  cout << st[i] << ' ';
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