//Educational Codeforces Round 172 (Rated for Div. 2) D. Recommendations
//https://codeforces.com/contest/2042/problem/D
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int ntests, n, res[N];
struct user{
    int l, r, idx;
} users[N];

bool cmp(user x, user y)
{
    return (x.l == y.l) ? x.r > y.r : x.l < y.l;
}

void solve()
{
    fill(res + 1, res + 1 + n, 0);
    cin >> n;
    for(int i = 1; i <= n; i++) 
    {
        cin >> users[i].l >> users[i].r;
        users[i].idx = i;
    }

    for(int q = 1; q <= 2; q++)
    {
        sort(users + 1, users + 1 + n, cmp);
        set<int> bounds;
        for(int i = 1; i <= n; i++)
        {
            auto it = bounds.lower_bound(users[i].r);
            if(it != bounds.end())
                res[users[i].idx] += (*it - users[i].r);
            bounds.insert(users[i].r);
        }

        for(int i = 1; i <= n; i++)
        {
            users[i].l = -users[i].l;
            users[i].r = -users[i].r;
            swap(users[i].l, users[i].r);
        }
    }

    map<pair<int, int>, int> cnt;
    for(int i = 1; i <= n; i++)
        cnt[{users[i].l, users[i].r}]++;
    for(int i = 1; i <= n; i++)
    {
        if(cnt[{users[i].l, users[i].r}] > 1)
            res[users[i].idx] = 0;
    }
    for(int i = 1; i <= n; i++)
        cout << res[i] << '\n';
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