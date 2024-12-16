//Codeforces Round 993 (Div. 4) D. Harder Problem
//https://codeforces.com/contest/2044/problem/D
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int ntests, n, a[N], b[N];

void solve()
{
    fill(b + 1, b + 1 + n, 0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }
    
    set<int> s;
    vector<int> ans;
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(b[i] == 0)
            q.push(i);
    }
    ans.push_back(a[1]);
    s.insert(a[1]);
    for(int i = 2; i <= n; i++)
    {
        if(s.count(a[i]) == 0)
        {
            s.insert(a[i]);
            ans.push_back(a[i]);
        }
        else
        {
            int c = q.front();
            q.pop();
            s.insert(c);
            ans.push_back(c);
        }
    }
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
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